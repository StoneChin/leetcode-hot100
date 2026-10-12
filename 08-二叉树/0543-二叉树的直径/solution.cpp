// 543. 二叉树的直径
// 原题：https://leetcode.cn/problems/diameter-of-binary-tree/
// 方法：求高度时顺便更新直径
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
    int ans = 0;
    int height(TreeNode* p) {
        if (!p) return 0;
        int l = height(p->left), r = height(p->right);
        ans = max(ans, l + r); // 在当前节点连接两条向下路径
        // 向父节点返回高度，只能选一条向下分支
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) { ans = 0; height(root); return ans; }
};
