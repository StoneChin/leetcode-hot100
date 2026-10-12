// 131. 分割回文串
// 原题：https://leetcode.cn/problems/palindrome-partitioning/
// 方法：预处理回文区间 + 枚举切分点
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
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n,vector<bool>(n));
        for(int l=n-1;l>=0;--l) for(int r=l;r<n;++r)
            // 先算内部区间，两端相等才能扩成更长回文
            pal[l][r]=s[l]==s[r] && (r-l<2 || pal[l+1][r-1]);
        vector<vector<string>> ans;
        vector<string> path;
        function<void(int)> dfs=[&](int start) {
            if(start==n) { ans.push_back(path); return; }
            for(int end=start;end<n;++end) if(pal[start][end]) {
                path.push_back(s.substr(start,end-start+1));
                dfs(end+1); path.pop_back();
            }
        };
        dfs(0); return ans;
    }
};
