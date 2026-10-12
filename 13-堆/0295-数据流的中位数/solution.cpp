// 295. 数据流的中位数
// 原题：https://leetcode.cn/problems/find-median-from-data-stream/
// 方法：两个堆分隔较小半边与较大半边
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

class MedianFinder {
    priority_queue<int> low;
    priority_queue<int,vector<int>,greater<int>> high;
public:
    MedianFinder() = default;
    void addNum(int num) {
        low.push(num);
        // 较小半边的最大值移入较大半边，维护数值分界
        high.push(low.top()); low.pop();
        if(high.size()>low.size()) { low.push(high.top()); high.pop(); }
    }
    double findMedian() {
        if(low.size()>high.size()) return low.top();
        return ((double)low.top()+high.top())/2.0;
    }
};
