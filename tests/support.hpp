#pragma once
#include <cassert>
#include <cstdlib>
#include <set>

// 仅供本地检查，字段和构造方式与题目接口一致。
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x=0, ListNode* p=nullptr) : val(x),next(p) {}
};
struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x=0,TreeNode* l=nullptr,TreeNode* r=nullptr) : val(x),left(l),right(r) {}
};
class Node {
public:
    int val;
    Node *next,*random;
    Node(int x) : val(x),next(nullptr),random(nullptr) {}
};
inline std::vector<int> values(ListNode* p) {
    std::vector<int> ans;
    std::set<ListNode*> visited;
    for(;p;p=p->next) {
        assert(visited.insert(p).second); // 意外形成环时立即报告
        ans.push_back(p->val);
    }
    return ans;
}
inline void freeList(ListNode* p) {
    while(p) { auto next=p->next; delete p; p=next; }
}
inline std::vector<int> inorder(TreeNode* p) {
    if(!p) return {};
    auto a=inorder(p->left); a.push_back(p->val);
    auto b=inorder(p->right); a.insert(a.end(),b.begin(),b.end());
    return a;
}
inline std::vector<int> preorder(TreeNode* p) {
    if(!p) return {};
    std::vector<int> a{p->val};
    auto l=preorder(p->left),r=preorder(p->right);
    a.insert(a.end(),l.begin(),l.end()); a.insert(a.end(),r.begin(),r.end());
    return a;
}
inline int balancedHeight(TreeNode* p) {
    if(!p) return 0;
    int l=balancedHeight(p->left),r=balancedHeight(p->right);
    if(l<0||r<0||std::abs(l-r)>1) return -1;
    return 1+std::max(l,r);
}
inline void freeTree(TreeNode* p) {
    if(!p) return;
    freeTree(p->left); freeTree(p->right); delete p;
}
