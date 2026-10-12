// 108. 将有序数组转换为二叉搜索树
// 原题：https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
// 方法：中点作根，递归处理两边
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
    TreeNode* build(const vector<int>& a, int l, int r) {
        if (l >= r) return nullptr;
        // 中点左右数量接近，递归构造出的树保持平衡
        int mid = l + (r - l) / 2;
        TreeNode* p = new TreeNode(a[mid]);
        p->left = build(a, l, mid);
        p->right = build(a, mid + 1, r);
        return p;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) { return build(nums, 0, nums.size()); }
};
