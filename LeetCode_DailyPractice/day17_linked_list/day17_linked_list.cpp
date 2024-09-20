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
    // 删除倒数第n个节点（可能是头节点、尾节点、中间节点）
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr) return head;

        int fast = 0;
        int slow = 0;

        // 使用虚拟头部节点避免删除头部节点时丢失head
        ListNode *dummyhead = new ListNode(0);
        dummyhead -> next = head;
        ListNode *cur = dummyhead;
        ListNode *temp;

        while(cur -> next){
            fast++;
            cur = cur -> next;
        }

        // cur移动到待删除节点前的节点
        slow = fast - n;
        cur = dummyhead;
        while(slow){
            cur = cur -> next;
            slow--;
        }

        // 待删除节点为尾部节点
        if(cur -> next -> next == nullptr){
            cur -> next = nullptr;
        }
        // 待删除节点为头部或中间节点
        else{
            temp = cur -> next;
            cur -> next = cur -> next -> next;
            delete temp;
            temp = nullptr;
        }

        return dummyhead -> next;
    }
};