// leetcode 24
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int val) : val(val), next(nullptr){}
    ListNode(int val, ListNaode *next): val(val),next(next){}
};

class Solution{
    public:
    // ���ڽڵ���������
    ListNode *swapPairs(ListNode* head) {

        ListNode *cur;
        ListNode *dummynode = new ListNode(0);
        dummynode -> next = head;               // ��������ڵ�
        cur = dummynode;                        // ��ǰ�ڵ�Ϊ�������������ڵ�ǰ�Ľڵ�

        // ע��ѭ����ֹ������cur -> nextΪ�����ʾ��ż�����ڵ㣬cur -> next -> nextΪ�����ʾ�������ڵ�
        while(cur -> next != nullptr && cur -> next -> next != nullptr){
            ListNode *temp1 = cur -> next;                     // ���ݴ��һ����ֹ��ʧ
            ListNode *temp2 = cur -> next -> next -> next;     // �ݴ����һ����ֹ��ʧ

            // ��ǰ�������򽻻����̣�ʱ��ע��ı����cur����dummynode
            cur -> next = cur -> next -> next;
            cur -> next -> next = temp1;
            cur -> next -> next -> next = temp2;

            // ������λ������һ��ڵ�
            cur = cur -> next -> next;
        }

        return dummynode -> next;
    }
};