// 1143. 最长公共子序列
// 原题：https://leetcode.cn/problems/longest-common-subsequence/
// 方法：两段前缀的最长公共子序列
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
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) {
            // 末尾相同，把这个公共字符接在两个更短前缀之后
            if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[m][n];
    }
};
