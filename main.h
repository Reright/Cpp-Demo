#include "handwrite.h"
#include "VariousofSort.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};


ListNode* MergeLists(ListNode* up, ListNode* down) {
// void MergeLists(ListNode* head, ListNode* up, ListNode* down) {
    // 此函数的功能是将up和down两个链表按序合并,head即表头
    // 先检查up/down是否为空
    if (!up && down) return down;
    if (up && !down) return up;
    auto uit = up, dit = down;  // i, j
    ListNode* head = new ListNode(0);
    auto it = head;  // k
    while (uit && dit) {
        if (uit->val <= dit->val) {
            it->next = uit; uit = uit->next;
        } else {
            it->next = dit; dit = dit->next;
        }
        it = it->next;
    }
    while (uit) {
        it->next = uit; uit = uit->next; it = it->next;
    }
    while (dit) {
        it->next = dit; dit = dit->next; it = it->next;
    }
    auto res = head->next;
    delete head; head = nullptr;
    auto li = res;
    while(li) {
        cout << li->val << "->";
        li = li->next;
    }
    cout << "NULL" << endl;
    return res;
}

void TestMergeLists()
{
    ListNode* left = new ListNode(0);
    auto li = left;
    ListNode* right = new ListNode(0);
    auto ri = right;
    for (int i = 3; i < 6; i++) {
        ri->next = new ListNode(i - 3);
        li->next = new ListNode(i);
        ri = ri->next; li = li->next;
    }
    li = left; ri = right;
    while(li) {
        cout << li->val << "->";
        li = li->next;
    }
    cout << "NULL" << endl;
    while(ri) {
        cout << ri->val << "->";
        ri = ri->next;
    }
    cout << "NULL" << endl;
    auto res = MergeLists(left, right);
    while(res) {
        cout << res->val << "->";
        res = res->next;
    }
    cout << "NULL" << endl;
}

