// 25. K 个一组翻转链表
// 原题：https://leetcode.cn/problems/reverse-nodes-in-k-group/
// 方法：先确认长度，再局部反转
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* before = &dummy;
        while (true) {
            ListNode* kth = before;
            for (int i = 0; i < k && kth; ++i) kth = kth->next;
            // 不足 k 个时整段保留，尚未修改任何连接
            if (!kth) break;
            ListNode* after = kth->next;
            ListNode* oldHead = before->next;
            ListNode *cur = oldHead, *prev = after;
            while (cur != after) {
                ListNode* next = cur->next;
                cur->next = prev; prev = cur; cur = next;
            }
            before->next = kth;
            before = oldHead; // 原组头现在是组尾
        }
        return dummy.next;
    }
};
