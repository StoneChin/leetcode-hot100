// 394. 字符串解码
// 原题：https://leetcode.cn/problems/decode-string/
// 方法：栈保存外层字符串与重复次数
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
    string decodeString(string s) {
        stack<pair<string,int>> st;
        string cur;
        int number=0;
        for(char c:s) {
            if(c>='0'&&c<='9') number=number*10+c-'0';
            else if(c=='[') { st.emplace(move(cur),number); cur.clear(); number=0; }
            else if(c==']') {
                // 当前层完成，取回外层前缀与本层重复次数
                auto [outer,times]=move(st.top()); st.pop();
                for(int i=0;i<times;++i) outer+=cur;
                cur=move(outer);
            } else cur.push_back(c);
        }
        return cur;
    }
};
