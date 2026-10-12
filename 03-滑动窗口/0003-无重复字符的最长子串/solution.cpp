// 3. 无重复字符的最长子串
// 原题：https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// 方法：滑动窗口 + 最近出现位置
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
    int lengthOfLongestSubstring(string s) {
        // 每个字符最近一次出现的位置，-1 表示尚未出现
        array<int, 256> last;
        last.fill(-1);
        int left = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            unsigned char c = s[right];
            left = max(left, last[c] + 1); // 左边界只向右走
            last[c] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
