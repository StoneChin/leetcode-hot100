// 105. 从前序与中序遍历序列构造二叉树
// 原题：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 方法：前序定根，中序划分左右区间
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
    unordered_map<int, int> pos;
    int next = 0;
    TreeNode* build(const vector<int>& pre, int l, int r) {
        if (l >= r) return nullptr;
        int value = pre[next++], mid = pos.at(value);
        TreeNode* p = new TreeNode(value);
        // 前序按根、左、右读取，所以必须先构造左子树
        p->left = build(pre, l, mid);
        p->right = build(pre, mid + 1, r);
        return p;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos.clear(); next = 0;
        for (int i = 0; i < (int)inorder.size(); ++i) pos[inorder[i]] = i;
        return build(preorder, 0, inorder.size());
    }
};
