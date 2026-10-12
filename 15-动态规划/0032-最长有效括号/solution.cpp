// 32. 最长有效括号
// 原题：https://leetcode.cn/problems/longest-valid-parentheses/
// 方法：栈保存匹配边界
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
    int longestValidParentheses(string s) {
        vector<int> st{-1};
        int ans=0;
        for(int i=0;i<(int)s.size();++i) {
            if(s[i]=='(') st.push_back(i);
            else {
                st.pop_back();
                // 当前右括号无法匹配，后续合法子串必须从它后面开始
                if(st.empty()) st.push_back(i);
                else ans=max(ans,i-st.back());
            }
        }
        return ans;
    }
};
