// 72. 编辑距离
// 原题：https://leetcode.cn/problems/edit-distance/
// 方法：前缀编辑距离
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
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;++i) dp[i][0]=i;
        for(int j=0;j<=n;++j) dp[0][j]=j;
        for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) {
            if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
            // 三个来源依次对应删除、插入、替换
            else dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
        return dp[m][n];
    }
};
