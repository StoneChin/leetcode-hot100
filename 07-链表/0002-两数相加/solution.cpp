// 2. 两数相加
// 原题：https://leetcode.cn/problems/add-two-numbers/
// 方法：逐位相加并保留进位
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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carry = 0;
        // 即使两个输入都结束，也不能丢掉最高位进位
        while (a || b || carry) {
            int sum = carry;
            if (a) { sum += a->val; a = a->next; }
            if (b) { sum += b->val; b = b->next; }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};
