// 437. 路径总和 III
// 原题：https://leetcode.cn/problems/path-sum-iii/
// 方法：树上的前缀和 + 回溯计数
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
    unordered_map<long long, int> count;
    int dfs(TreeNode* p, long long sum, long long target) {
        if (!p) return 0;
        sum += p->val;
        int ans = 0;
        auto it = count.find(sum - target);
        if (it != count.end()) ans = it->second;
        // 当前前缀只在访问其后代期间有效，退出时撤销
        ++count[sum];
        ans += dfs(p->left, sum, target);
        ans += dfs(p->right, sum, target);
        if (--count[sum] == 0) count.erase(sum); // 离开当前根路径
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        count.clear(); count[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
