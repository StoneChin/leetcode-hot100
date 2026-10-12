// 230. 二叉搜索树中第 K 小的元素
// 原题：https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
// 方法：中序遍历数到第 k 个
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) { st.push(root); root = root->left; }
            root = st.top(); st.pop();
            // 弹出时才真正访问节点，中序顺序就是从小到大
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1; // 合法 k 不会走到这里
    }
};
