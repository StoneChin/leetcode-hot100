#!/usr/bin/env python3
"""检查题单完整性，并独立编译、运行每道题的本地回归用例。"""
import argparse
import concurrent.futures
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
COUNTS = {'哈希': 3, '双指针': 4, '滑动窗口': 2, '子串': 3, '普通数组': 5,
          '矩阵': 4, '链表': 14, '二叉树': 15, '图论': 4, '回溯': 8,
          '二分查找': 6, '栈': 5, '堆': 3, '贪心算法': 4, '动态规划': 10,
          '多维动态规划': 5, '技巧': 5}


def validate():
    problems = json.loads((ROOT / 'problems.json').read_text())
    cases = json.loads((ROOT / 'tests/cases.json').read_text())
    extra = json.loads((ROOT / 'tests/exhaustive.json').read_text())
    ids = [str(p['id']) for p in problems]
    if len(ids) != 100 or len(set(ids)) != 100 or set(ids) != set(cases):
        raise ValueError('题目必须恰好有 100 个不同编号，并且每题都有用例')
    counts = {}
    for p in problems:
        counts[p['category']] = counts.get(p['category'], 0) + 1
        folder = ROOT / p['path']
        for name in ('README.md', 'solution.cpp'):
            if not (folder / name).is_file():
                raise ValueError(f'缺少文件：{folder / name}')
        doc = (folder / 'README.md').read_text()
        for heading in ('要解决什么', '怎么想到这个方法', '跟着例子走一遍', '写代码时注意什么', '复杂度'):
            if f'## {heading}' not in doc:
                raise ValueError(f'{p["id"]} 缺少解析：{heading}')
    if counts != COUNTS:
        raise ValueError(f'分类题数不符：{counts}')
    actual = {p.parent.relative_to(ROOT).as_posix() for p in ROOT.glob('*/*/solution.cpp')}
    if actual != {p['path'] for p in problems}:
        raise ValueError('实际题目目录与 problems.json 不一致')
    # 本地 Markdown 链接必须可达，包括中文及带空格的文件夹名。
    for doc in ROOT.rglob('*.md'):
        for link in re.findall(r'\]\(([^)]+)\)', doc.read_text()):
            if '://' not in link and not link.startswith('#'):
                if not (doc.parent / link.split('#')[0]).exists():
                    raise ValueError(f'失效链接：{doc.relative_to(ROOT)} -> {link}')
    return problems, cases, extra


def run_one(p, cases, extra, compiler, work):
    ident = str(p['id'])
    source = work / f'{ident}.cpp'
    binary = work / f'{ident}.bin'
    include = (ROOT / p['path'] / 'solution.cpp').as_posix()
    source.write_text('#define LOCAL_TEST\n#include ' + json.dumps(include, ensure_ascii=False)
                      + '\nint main() {\n' + cases[ident] + '\n'
                      + extra.get(ident, '') + '\n}\n')
    try:
        subprocess.run([compiler, '-std=c++17', '-O1', '-Wall', '-Wextra', '-pedantic',
                        str(source), '-o', str(binary)], check=True,
                       capture_output=True, text=True, timeout=90)
        subprocess.run([str(binary)], check=True, capture_output=True, text=True, timeout=30)
        return ident, None
    except (subprocess.CalledProcessError, subprocess.TimeoutExpired) as e:
        return ident, str(e) + '\n' + (e.stderr or '')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--ids', nargs='+', type=int, help='只运行指定题号')
    parser.add_argument('--compiler', default=os.environ.get('CXX', 'g++'))
    parser.add_argument('--jobs', type=int, default=min(4, os.cpu_count() or 1))
    args = parser.parse_args()
    if args.jobs < 1:
        parser.error('--jobs 必须为正数')
    if shutil.which(args.compiler) is None:
        parser.error(f'找不到编译器：{args.compiler}')
    problems, cases, extra = validate()
    if args.ids:
        missing = set(args.ids) - {p['id'] for p in problems}
        if missing:
            parser.error(f'未知题号：{sorted(missing)}')
        problems = [p for p in problems if p['id'] in args.ids]
    print(f'目录、分类、文档链接校验通过；开始检查 {len(problems)} 题。', flush=True)
    failures = []
    with tempfile.TemporaryDirectory(prefix='hot100-check-') as tmp:
        with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
            futures = [pool.submit(run_one, p, cases, extra, args.compiler, Path(tmp)) for p in problems]
            for done, f in enumerate(concurrent.futures.as_completed(futures), 1):
                ident, error = f.result()
                if error:
                    failures.append(ident)
                    print(f'FAIL {ident}\n{error}', flush=True)
                elif done % 10 == 0 or done == len(problems):
                    print(f'进度 {done}/{len(problems)}', flush=True)
    if failures:
        raise SystemExit(f'失败题号：{", ".join(failures)}')
    print(f'通过：{len(problems)}/{len(problems)} 题（独立编译 + 用例运行）。')


if __name__ == '__main__':
    main()
