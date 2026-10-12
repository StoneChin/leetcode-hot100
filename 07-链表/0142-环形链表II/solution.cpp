// 142. 环形链表 II
// 原题：https://leetcode.cn/problems/linked-list-cycle-ii/
// 方法：相遇后同步走向环入口
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
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next; fast = fast->next->next;
            if (slow == fast) {
                // 头节点与相遇点同步走，首次相遇处就是入口
                ListNode* p = head;
                while (p != slow) { p = p->next; slow = slow->next; }
                return p;
            }
        }
        return nullptr;
    }
};
