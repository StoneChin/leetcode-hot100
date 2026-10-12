// 146. LRU 缓存
// 原题：https://leetcode.cn/problems/lru-cache/
// 方法：哈希表定位 + 双向链表维护新旧
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

class LRUCache {
    int capacity;
    list<pair<int, int>> recent; // 头部最新，尾部最旧
    unordered_map<int, list<pair<int, int>>::iterator> pos;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;
    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        // 移动节点不使迭代器失效，哈希表无需更新地址
        recent.splice(recent.begin(), recent, it->second);
        return it->second->second;
    }
    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            recent.splice(recent.begin(), recent, it->second);
            return;
        }
        if (capacity <= 0) return;
        if ((int)recent.size() == capacity) {
            pos.erase(recent.back().first);
            recent.pop_back();
        }
        recent.emplace_front(key, value);
        pos[key] = recent.begin();
    }
};
