// 124. 二叉树中的最大路径和
// 原题：https://leetcode.cn/problems/binary-tree-maximum-path-sum/
// 方法：单边贡献上传，双边路径更新答案
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
    int ans = INT_MIN;
    int gain(TreeNode* p) {
        if (!p) return 0;
        // 负贡献宁可不选，但当前节点必须纳入非空路径
        int l = max(0, gain(p->left)), r = max(0, gain(p->right));
        ans = max(ans, p->val + l + r);
        return p->val + max(l, r); // 父节点只能接一条分支
    }
public:
    int maxPathSum(TreeNode* root) { ans = INT_MIN; gain(root); return ans; }
};
