// 79. 单词搜索
// 原题：https://leetcode.cn/problems/word-search/
// 方法：网格回溯，当前路径禁止复用格子
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
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty()||board[0].empty()) return false;
        int m=board.size(), n=board[0].size();
        function<bool(int,int,int)> dfs=[&](int i,int j,int k) {
            if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[k]) return false;
            if(k+1==(int)word.size()) return true;
            char saved=board[i][j]; board[i][j]='\0';
            bool found=dfs(i-1,j,k+1)||dfs(i+1,j,k+1)||dfs(i,j-1,k+1)||dfs(i,j+1,k+1);
            // 无论成功失败都恢复，不能影响其他搜索路径
            board[i][j]=saved;
            return found;
        };
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) if(dfs(i,j,0)) return true;
        return false;
    }
};
