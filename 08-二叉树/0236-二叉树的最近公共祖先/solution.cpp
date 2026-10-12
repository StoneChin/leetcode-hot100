// 236. 二叉树的最近公共祖先
// 原题：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// 方法：后序递归汇合两个目标
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        // 两个目标分别出现在两边，此处就是它们的汇合点
        if (l && r) return root;
        return l ? l : r;
    }
};
