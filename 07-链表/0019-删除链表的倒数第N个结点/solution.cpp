// 19. 删除链表的倒数第 N 个结点
// 原题：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
// 方法：固定间距的快慢指针
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *fast = &dummy, *slow = &dummy;
        // 保持 n 个节点的距离，slow 最终停在待删节点之前
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast->next) { fast = fast->next; slow = slow->next; }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
