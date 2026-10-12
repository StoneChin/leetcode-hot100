// 114. 二叉树展开为链表
// 原题：https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
// 方法：把左子树插入根与右子树之间
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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* tail = root->left;
                while (tail->right) tail = tail->right;
                // 先保留原右子树，再把左子树整体移到右边
                tail->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
