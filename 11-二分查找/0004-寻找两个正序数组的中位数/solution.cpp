// 4. 寻找两个正序数组的中位数
// 原题：https://leetcode.cn/problems/median-of-two-sorted-arrays/
// 方法：在较短数组上二分分割线
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
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()) return findMedianSortedArrays(b,a);
        int m=a.size(),n=b.size(),half=(m+n+1)/2,l=0,r=m;
        while(l<=r) {
            // 固定左半总数，只需二分其中一个分割位置
            int i=l+(r-l)/2,j=half-i;
            int al=i?a[i-1]:INT_MIN, ar=i<m?a[i]:INT_MAX;
            int bl=j?b[j-1]:INT_MIN, br=j<n?b[j]:INT_MAX;
            if(al<=br && bl<=ar) {
                if((m+n)%2) return max(al,bl);
                return ((double)max(al,bl)+min(ar,br))/2.0;
            }
            if(al>br) r=i-1; else l=i+1;
        }
        return 0; // 合法的有序输入一定会找到分割
    }
};
