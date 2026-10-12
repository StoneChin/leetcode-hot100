// 22. 括号生成
// 原题：https://leetcode.cn/problems/generate-parentheses/
// 方法：只生成合法前缀
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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        function<void(int,int)> dfs=[&](int left,int right) {
            if((int)path.size()==2*n) { ans.push_back(path); return; }
            if(left<n) { path.push_back('('); dfs(left+1,right); path.pop_back(); }
            // 右括号不能多于已放的左括号，保证前缀始终合法
            if(right<left) { path.push_back(')'); dfs(left,right+1); path.pop_back(); }
        };
        dfs(0,0); return ans;
    }
};
