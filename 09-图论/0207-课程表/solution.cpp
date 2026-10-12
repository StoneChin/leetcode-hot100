// 207. 课程表
// 原题：https://leetcode.cn/problems/course-schedule/
// 方法：入度拓扑排序
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> next(numCourses);
        vector<int> degree(numCourses);
        for(auto& p:prerequisites) { next[p[1]].push_back(p[0]); ++degree[p[0]]; }
        queue<int> q;
        for(int i=0;i<numCourses;++i) if(degree[i]==0) q.push(i);
        int done=0;
        while(!q.empty()) {
            int u=q.front(); q.pop(); ++done;
            // 只有全部先修课完成，后续课程才可进入队列
            for(int v:next[u]) if(--degree[v]==0) q.push(v);
        }
        return done==numCourses;
    }
};
