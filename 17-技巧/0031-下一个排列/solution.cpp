// 31. 下一个排列
// 原题：https://leetcode.cn/problems/next-permutation/
// 方法：找右侧升序断点，交换后反转后缀
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
    void nextPermutation(vector<int>& nums) {
        int i=(int)nums.size()-2;
        // 右侧非递增后缀已经最大，找到能增大的最右位置
        while(i>=0&&nums[i]>=nums[i+1]) --i;
        if(i>=0) {
            int j=(int)nums.size()-1;
            while(nums[j]<=nums[i]) --j;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
