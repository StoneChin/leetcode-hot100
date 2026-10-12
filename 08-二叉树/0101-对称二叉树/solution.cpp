// 101. 对称二叉树
// 原题：https://leetcode.cn/problems/symmetric-tree/
// 方法：成对比较镜像位置
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
    bool mirror(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a == b;
        // 镜像比较的是外侧对外侧、内侧对内侧
        return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
    }
public:
    bool isSymmetric(TreeNode* root) { return !root || mirror(root->left, root->right); }
};
