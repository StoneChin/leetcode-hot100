// 5. 最长回文子串
// 原题：https://leetcode.cn/problems/longest-palindromic-substring/
// 方法：枚举奇偶两类回文中心
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
    string longestPalindrome(string s) {
        int start=0,best=0,n=s.size();
        auto expand=[&](int l,int r) {
            while(l>=0&&r<n&&s[l]==s[r]) { --l; ++r; }
            // 退出时 l、r 已越过回文两端，实际区间为 [l+1,r)
            int len=r-l-1;
            if(len>best) { best=len; start=l+1; }
        };
        for(int i=0;i<n;++i) { expand(i,i); expand(i,i+1); }
        return s.substr(start,best);
    }
};
