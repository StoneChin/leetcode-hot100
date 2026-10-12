// 17. 电话号码的字母组合
// 原题：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
// 方法：按数字逐层选择字母
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
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> keys{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string path;
        function<void(int)> dfs=[&](int i) {
            if(i==(int)digits.size()) { ans.push_back(path); return; }
            // 本层只选择当前数字的字母，返回后撤销再换一个
            for(char c:keys[digits[i]-'0']) { path.push_back(c); dfs(i+1); path.pop_back(); }
        };
        dfs(0); return ans;
    }
};
