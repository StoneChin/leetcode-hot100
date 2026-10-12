// 104. 二叉树的最大深度
// 原题：https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// 方法：递归求左右子树高度
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
    int maxDepth(TreeNode* root) {
        // 空树为 0 层，单节点通过下面的 +1 得到 1 层
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
