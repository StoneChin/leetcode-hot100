// 75. 颜色分类
// 原题：https://leetcode.cn/problems/sort-colors/
// 方法：荷兰国旗三路划分
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
    void sortColors(vector<int>& nums) {
        int low=0,i=0,high=(int)nums.size()-1;
        while(i<=high) {
            if(nums[i]==0) swap(nums[low++],nums[i++]);
            // 换回来的数还未检查，所以 i 暂时不动
            else if(nums[i]==2) swap(nums[i],nums[high--]);
            else ++i;
        }
    }
};
