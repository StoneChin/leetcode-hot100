// 118. 杨辉三角
// 原题：https://leetcode.cn/problems/pascals-triangle/
// 方法：按上一行构造下一行
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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;++i) {
            // 当前行先填 1，两端不必单独赋值
            ans.emplace_back(i+1,1);
            for(int j=1;j<i;++j) ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
        return ans;
    }
};
