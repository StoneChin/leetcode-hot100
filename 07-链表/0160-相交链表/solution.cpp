// 160. 相交链表
// 原题：https://leetcode.cn/problems/intersection-of-two-linked-lists/
// 方法：双指针交换起点
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            // 走完后改走另一条链表，让两者抵消长度差
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
