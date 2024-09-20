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
    // Ѱ���������Ĺ�����
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0;
        int lenB = 0;
        int diff = 0;

        // ������A����
        while(curA){
            curA = curA -> next;
            lenA++;
        }

        // ������B����
        while(curB){
            curB = curB -> next;
            lenB++;
        }

        // ���������Ӻ���ǰ���䣬Ȼ���ƶ��ϳ������������϶�������
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
                if(curA == curB) return curA;      // ע��ؼ���ָ��ָ���ַ��ͬ������ֵ��ͬ
                curA = curA -> next;
                curB = curB -> next;
            }
        }

        return nullptr;
    }
};