// 84. 柱状图中最大的矩形
// 原题：https://leetcode.cn/problems/largest-rectangle-in-histogram/
// 方法：递增栈确定矩形左右边界
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
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;
        int ans=0,n=heights.size();
        for(int i=0;i<=n;++i) {
            int cur=i==n?0:heights[i];
            while(!st.empty() && heights[st.back()]>cur) {
                int h=heights[st.back()]; st.pop_back();
                // 弹出后再确定左界，左右边界本身都不包含在矩形内
                int left=st.empty()?-1:st.back();
                ans=max(ans,h*(i-left-1));
            }
            if(i<n) st.push_back(i);
        }
        return ans;
    }
};
