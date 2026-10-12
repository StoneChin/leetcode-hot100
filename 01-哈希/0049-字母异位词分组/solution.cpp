// 49. 字母异位词分组
// 原题：https://leetcode.cn/problems/group-anagrams/
// 方法：排序后的字符串作键
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 排序后的拼写相同，就归入同一个分组
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // 同组字符串具有相同的键
            groups[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& entry : groups) ans.push_back(move(entry.second));
        return ans;
    }
};
