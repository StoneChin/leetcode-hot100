// 139. 单词拆分
// 原题：https://leetcode.cn/problems/word-break/
// 方法：前缀能否被完整拆分
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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int longest=0,n=s.size();
        for(const auto& w:wordDict) longest=max(longest,(int)w.size());
        vector<bool> dp(n+1,false); dp[0]=true;
        for(int i=1;i<=n;++i)
            for(int j=i-1;j>=max(0,i-longest);--j)
                // 前缀可拆且最后一段在字典中，才构成完整切分
                if(dp[j] && dict.count(s.substr(j,i-j))) { dp[i]=true; break; }
        return dp[n];
    }
};
