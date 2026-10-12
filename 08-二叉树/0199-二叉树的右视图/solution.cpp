// 199. 二叉树的右视图
// 原题：https://leetcode.cn/problems/binary-tree-right-side-view/
// 方法：层序遍历取最后一个节点
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q; q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto p = q.front(); q.pop();
                // 孩子先左后右入队，本层最后一个就是右视图节点
                if (i == size - 1) ans.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        return ans;
    }
};
