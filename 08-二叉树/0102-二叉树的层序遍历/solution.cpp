// 102. 二叉树的层序遍历
// 原题：https://leetcode.cn/problems/binary-tree-level-order-traversal/
// 方法：队列按层遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q; q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            // 固定本层节点数，新加入的孩子留给下一层
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                auto p = q.front(); q.pop();
                level.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            ans.push_back(move(level));
        }
        return ans;
    }
};
