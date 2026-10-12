// 74. 搜索二维矩阵
// 原题：https://leetcode.cn/problems/search-a-2d-matrix/
// 方法：把矩阵视作一维有序数组
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int n=matrix[0].size(),l=0,r=(int)matrix.size()*n-1;
        while(l<=r) {
            // 除以列数得行号，取余得列号，不必复制成一维数组
            int mid=l+(r-l)/2, x=matrix[mid/n][mid%n];
            if(x==target) return true;
            if(x<target) l=mid+1; else r=mid-1;
        }
        return false;
    }
};
