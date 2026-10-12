// 20. 有效的括号
// 原题：https://leetcode.cn/problems/valid-parentheses/
// 方法：栈保存尚未匹配的左括号
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
    bool isValid(string s) {
        stack<char> st;
        for(char c:s) {
            if(c=='('||c=='['||c=='{') st.push(c);
            else {
                char want=c==')'?'(':c==']'?'[':'{';
                // 右括号只能匹配最近一个尚未闭合的左括号
                if(st.empty()||st.top()!=want) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
