// leetcode 19
#include<iostream>

using namespace std;

struct  ListNode
{
    int val;
    ListNode *next;

    ListNode(): val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val,ListNode *next): val(val), next(next){}
};

class Solution{
    public:
    // ɾ��������n���ڵ㣨������ͷ�ڵ㡢β�ڵ㡢�м�ڵ㣩
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr) return head;

        int fast = 0;
        int slow = 0;

        // ʹ������ͷ���ڵ����ɾ��ͷ���ڵ�ʱ��ʧhead
        ListNode *dummyhead = new ListNode(0);
        dummyhead -> next = head;
        ListNode *cur = dummyhead;
        ListNode *temp;

        while(cur -> next){
            fast++;
            cur = cur -> next;
        }

        // cur�ƶ�����ɾ���ڵ�ǰ�Ľڵ�
        slow = fast - n;
        cur = dummyhead;
        while(slow){
            cur = cur -> next;
            slow--;
        }

        // ��ɾ���ڵ�Ϊβ���ڵ�
        if(cur -> next -> next == nullptr){
            cur -> next = nullptr;
        }
        // ��ɾ���ڵ�Ϊͷ�����м�ڵ�
        else{
            temp = cur -> next;
            cur -> next = cur -> next -> next;
            delete temp;
            temp = nullptr;
        }

        return dummyhead -> next;
    }
};