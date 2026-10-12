// 739. 每日温度
// 原题：https://leetcode.cn/problems/daily-temperatures/
// 方法：单调栈保存还没等到升温的日期
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
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(),0), st;
        for(int i=0;i<(int)t.size();++i) {
            while(!st.empty() && t[i]>t[st.back()]) {
                // 今天是 j 之后遇到的第一个严格更暖的日子
                int j=st.back(); st.pop_back(); ans[j]=i-j;
            }
            st.push_back(i);
        }
        return ans;
    }
};
