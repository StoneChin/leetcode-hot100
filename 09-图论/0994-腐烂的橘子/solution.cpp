// 994. 腐烂的橘子
// 原题：https://leetcode.cn/problems/rotting-oranges/
// 方法：多源广度优先搜索
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
    int orangesRotting(vector<vector<int>>& g) {
        if (g.empty() || g[0].empty()) return 0;
        int m=g.size(), n=g[0].size(), fresh=0, minutes=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) {
            if(g[i][j]==2) q.emplace(i,j);
            if(g[i][j]==1) ++fresh;
        }
        int d[5]={-1,0,1,0,-1};
        while(fresh && !q.empty()) {
            int size=q.size();
            while(size--) {
                auto [i,j]=q.front(); q.pop();
                for(int k=0;k<4;++k) {
                    int x=i+d[k], y=j+d[k+1];
                    if(x<0||x>=m||y<0||y>=n||g[x][y]!=1) continue;
                    // 入队时立即标记，避免被不同感染源重复入队
                    g[x][y]=2; --fresh; q.emplace(x,y);
                }
            }
            ++minutes;
        }
        return fresh ? -1 : minutes;
    }
};
