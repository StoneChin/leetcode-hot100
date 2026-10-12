// 208. 实现 Trie (前缀树)
// 原题：https://leetcode.cn/problems/implement-trie-prefix-tree/
// 方法：按字符建前缀树
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

class Trie {
    struct Entry {
        array<int,26> child;
        bool end=false;
        Entry() { child.fill(-1); }
    };
    vector<Entry> nodes;
    int find(const string& s) const {
        int p=0;
        for(char c:s) { p=nodes[p].child[c-'a']; if(p==-1) return -1; }
        return p;
    }
public:
    // 扩容可能移动节点，后面用整数下标重新访问
    Trie() { nodes.emplace_back(); }
    void insert(string word) {
        int p=0;
        for(char c:word) {
            int x=c-'a';
            if(nodes[p].child[x]==-1) {
                int id=nodes.size();
                nodes.emplace_back();
                nodes[p].child[x]=id;
            }
            p=nodes[p].child[x];
        }
        nodes[p].end=true;
    }
    bool search(string word) { int p=find(word); return p!=-1 && nodes[p].end; }
    bool startsWith(string prefix) { return find(prefix)!=-1; }
};
