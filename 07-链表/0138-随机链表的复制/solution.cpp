// 138. 随机链表的复制
// 原题：https://leetcode.cn/problems/copy-list-with-random-pointer/
// 方法：两趟遍历 + 节点映射
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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;
        // 空 next 或 random 仍映射为空指针
        copy[nullptr] = nullptr;
        for (Node* p = head; p; p = p->next) copy[p] = new Node(p->val);
        for (Node* p = head; p; p = p->next) {
            copy[p]->next = copy[p->next];
            copy[p]->random = copy[p->random];
        }
        return copy[head];
    }
};
