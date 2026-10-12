// 51. N 皇后
// 原题：https://leetcode.cn/problems/n-queens/
// 方法：逐行放皇后，标记列与对角线
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> col(n), d1(2*n-1), d2(2*n-1);
        function<void(int)> dfs=[&](int r) {
            if(r==n) { ans.push_back(board); return; }
            for(int c=0;c<n;++c) {
                // 行列差固定在一条主对角线，行列和固定在一条副对角线
                int a=r-c+n-1,b=r+c;
                if(col[c]||d1[a]||d2[b]) continue;
                board[r][c]='Q'; col[c]=d1[a]=d2[b]=1;
                dfs(r+1);
                board[r][c]='.'; col[c]=d1[a]=d2[b]=0;
            }
        };
        dfs(0); return ans;
    }
};
