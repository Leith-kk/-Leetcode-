// leetcode 206
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    Node(): val(0), next(nullptr){}
    Node(int val) : val(val), next(nullptr){}
    Node(int val, ListNode *next) : val(val),next(nullptr)
};

class Soltion{
    public:
    // 双指针法
    ListNode *ReverseList(ListNode *head){
        ListNode *temp;                    // 用于暂存当前节点原来的指针指向，避免丢失链表；
        ListNode *cur = head;              // cur 初始时指向头节点
        ListNode *pre = nullptr;           // pre初始在cur节点之前
        while(cur){
            temp = cur -> next;
            cur -> next = pre;
            pre = cur;                     // 将pre向后移动
            cur = temp;                    // 将cur向后移动
        }
        return pre;
    }

    // 递归法(与双指针类似)
    ListNode * ReverseList(ListNode *head){
        ListNode *cur = head;
        ListNode *pre = nullptr;
        return reverse(cur, pre);
    }

    ListNode *reverse(ListNode *cur, ListNode *pre){
        if(cur == nullptr) return pre;
        ListNode *temp = cur -> next;
        cur -> next = pre;
        return reverse(temp,cur);
    }

};
