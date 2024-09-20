// leetcode 142
// ��⣺https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(nullptr){}
};

class Solution{
    public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            // fast���slow���ƶ�һ����˶���һ����������������ѧ��������ʱslow��û�߹�������һ����
            slow = slow->next;
            fast = fast->next->next;

            // ����ָ����������ʱ��head��������ͬʱ����ֱ������
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // ���ػ������
            }
        }
        return NULL;
    }
};