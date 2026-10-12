// 234. 回文链表
// 原题：https://leetcode.cn/problems/palindrome-linked-list/
// 方法：找中点 + 反转后半段
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
    ListNode* reverse(ListNode* p) {
        ListNode* prev = nullptr;
        while (p) { auto next = p->next; p->next = prev; prev = p; p = next; }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }
        // slow 停在前半段末尾，只反转后半段
        ListNode* second = reverse(slow->next);
        bool ok = true;
        for (ListNode *a = head, *b = second; b; a = a->next, b = b->next)
            if (a->val != b->val) ok = false;
        slow->next = reverse(second); // 比较后恢复原链表
        return ok;
    }
};
