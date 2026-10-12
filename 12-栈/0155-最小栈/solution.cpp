// 155. 最小栈
// 原题：https://leetcode.cn/problems/min-stack/
// 方法：每层同时保存当前最小值
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

class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() = default;
    void push(int val) {
        // 每层保存当时最小值，弹出后自动恢复旧最小值
        int low=st.empty()?val:min(val,st.top().second);
        st.emplace(val,low);
    }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
