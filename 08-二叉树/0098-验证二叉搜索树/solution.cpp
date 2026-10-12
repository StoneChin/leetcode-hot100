// 98. 验证二叉搜索树
// 原题：https://leetcode.cn/problems/validate-binary-search-tree/
// 方法：递归传递严格上下界
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
    bool check(TreeNode* p, long long low, long long high) {
        if (!p) return true;
        // 范围来自所有祖先，并且必须严格位于边界之内
        if (p->val <= low || p->val >= high) return false;
        return check(p->left, low, p->val) && check(p->right, p->val, high);
    }
public:
    bool isValidBST(TreeNode* root) { return check(root, LLONG_MIN, LLONG_MAX); }
};
