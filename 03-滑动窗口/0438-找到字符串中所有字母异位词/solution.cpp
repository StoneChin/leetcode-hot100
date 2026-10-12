// 438. 找到字符串中所有字母异位词
// 原题：https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// 方法：固定长度窗口 + 字母计数
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// 力扣提供节点定义；本地检查时使用统一的测试定义。
#ifdef LOCAL_TEST
#include "../../tests/support.hpp"
#endif

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int, 26> need{}, have{};
        for (char c : p) ++need[c - 'a'];
        vector<int> ans;
        int m = (int)p.size();
        for (int r = 0; r < (int)s.size(); ++r) {
            ++have[s[r] - 'a'];
            // 窗口只保留最近 m 个字符，移除刚滑出的那个
            if (r >= m) --have[s[r - m] - 'a'];
            if (r + 1 >= m && have == need) ans.push_back(r - m + 1);
        }
        return ans;
    }
};
