// 94. 二叉树的中序遍历
// 原题：https://leetcode.cn/problems/binary-tree-inorder-traversal/
// 方法：显式栈模拟中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            // 先走到底，再从栈中找回尚未访问的祖先
            while (cur) { st.push(cur); cur = cur->left; }
            cur = st.top(); st.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
