// 23. 合并 K 个升序链表
// 原题：https://leetcode.cn/problems/merge-k-sorted-lists/
// 方法：最小堆维护各条链表的头
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
    struct Greater {
        bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Greater> heap;
        for (auto p : lists) if (p) heap.push(p);
        ListNode dummy;
        ListNode* tail = &dummy;
        while (!heap.empty()) {
            ListNode* p = heap.top(); heap.pop();
            // 该链表的下一个候选补进堆，其他链表不动
            if (p->next) heap.push(p->next);
            tail->next = p; tail = p;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
