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
    // 相邻节点两两交换
    ListNode *swapPairs(ListNode* head) {

        ListNode *cur;
        ListNode *dummynode = new ListNode(0);
        dummynode -> next = head;               // 定义虚拟节点
        cur = dummynode;                        // 当前节点为待交换的两个节点前的节点

        // 注意循环截止条件，cur -> next为空则表示是偶数个节点，cur -> next -> next为空则表示奇数个节点
        while(cur -> next != nullptr && cur -> next -> next != nullptr){
            ListNode *temp1 = cur -> next;                     // 先暂存第一步防止丢失
            ListNode *temp2 = cur -> next -> next -> next;     // 暂存最后一步防止丢失

            // 从前到后逐序交换过程，时刻注意改变的是cur不是dummynode
            cur -> next = cur -> next -> next;
            cur -> next -> next = temp1;
            cur -> next -> next -> next = temp2;

            // 后移两位处理下一组节点
            cur = cur -> next -> next;
        }

        return dummynode -> next;
    }
};