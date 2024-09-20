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
    // ˫ָ�뷨
    ListNode *ReverseList(ListNode *head){
        ListNode *temp;                    // �����ݴ浱ǰ�ڵ�ԭ����ָ��ָ�򣬱��ⶪʧ����
        ListNode *cur = head;              // cur ��ʼʱָ��ͷ�ڵ�
        ListNode *pre = nullptr;           // pre��ʼ��cur�ڵ�֮ǰ
        while(cur){
            temp = cur -> next;
            cur -> next = pre;
            pre = cur;                     // ��pre����ƶ�
            cur = temp;                    // ��cur����ƶ�
        }
        return pre;
    }

    // �ݹ鷨(��˫ָ������)
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
