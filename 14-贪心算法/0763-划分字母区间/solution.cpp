// 763. 划分字母区间
// 原题：https://leetcode.cn/problems/partition-labels/
// 方法：用字符最后位置确定分段终点
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
    vector<int> partitionLabels(string s) {
        array<int,26> last{};
        for(int i=0;i<(int)s.size();++i) last[s[i]-'a']=i;
        int start=0,end=0;
        vector<int> ans;
        for(int i=0;i<(int)s.size();++i) {
            // 本段包含的每个字母，其最后一次出现都要纳入本段
            end=max(end,last[s[i]-'a']);
            if(i==end) { ans.push_back(i-start+1); start=i+1; }
        }
        return ans;
    }
};
