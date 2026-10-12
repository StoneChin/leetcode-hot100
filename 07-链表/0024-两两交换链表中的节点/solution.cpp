// 24. 两两交换链表中的节点
// 原题：https://leetcode.cn/problems/swap-nodes-in-pairs/
// 方法：成对调整三条连接
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;
            ListNode* b = a->next;
            // 先接回后续，再把 b 接到 a 前面
            a->next = b->next;
            b->next = a;
            prev->next = b;
            prev = a;
        }
        return dummy.next;
    }
};
