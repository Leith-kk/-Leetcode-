// leetcode 02.07

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class Solution{
    public:
    // 寻找两个链的公共点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0;
        int lenB = 0;
        int diff = 0;

        // 计算链A长度
        while(curA){
            curA = curA -> next;
            lenA++;
        }

        // 计算链B长度
        while(curB){
            curB = curB -> next;
            lenB++;
        }

        // 将两个链从后向前对其，然后移动较长链的起点至与较短链对齐
        curA = headA;
        curB = headB;
        if(lenA > lenB)
        {
            diff = lenA - lenB;
            while(diff--){
                curA = curA -> next;
            }

            while(curA){
                if(curA == curB) return curA;
                curA = curA -> next;
                curB = curB -> next;
            }
        }
        else{
            diff = lenB - lenA;
            while(diff--){
                curB = curB -> next;
            }

            while(curB){
                if(curA == curB) return curA;      // 注意关键在指针指向地址相同，不在值相同
                curA = curA -> next;
                curB = curB -> next;
            }
        }

        return nullptr;
    }
};