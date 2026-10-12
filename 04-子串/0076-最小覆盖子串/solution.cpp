// 76. 最小覆盖子串
// 原题：https://leetcode.cn/problems/minimum-window-substring/
// 方法：计数滑动窗口
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
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        array<int, 256> need{};
        for (unsigned char c : t) ++need[c];
        // missing 按字符总次数计数，不是按不同种类计数
        int missing = (int)t.size(), left = 0, start = 0, best = INT_MAX;
        for (int right = 0; right < (int)s.size(); ++right) {
            unsigned char c = s[right];
            if (need[c] > 0) --missing;
            --need[c];
            while (missing == 0) {
                if (right - left + 1 < best) { start = left; best = right - left + 1; }
                unsigned char out = s[left++];
                if (++need[out] > 0) ++missing; // 移走了必需的一个字符
            }
        }
        return best == INT_MAX ? "" : s.substr(start, best);
    }
};
