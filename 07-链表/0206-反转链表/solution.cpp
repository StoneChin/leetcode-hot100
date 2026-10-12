// 206. 反转链表
// 原题：https://leetcode.cn/problems/reverse-linked-list/
// 方法：逐个反转 next
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next; // 改指针前先保存剩余链表
            // 让当前节点指回已经反转好的部分
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
