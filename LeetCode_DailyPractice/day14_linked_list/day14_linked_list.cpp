// leetcode 707
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}

};

class MyLinkedList {
    private:
        int size;
        ListNode *dummyhead;

    public:
        // 类构造函数 
        MyLinkedList() {
            this->size = 0;
            this->dummyhead = new ListNode(0);       //虚拟头节点
        }
        
        // 根据下标获取数值(下标从0开始)
        int get(int index) {
            if(index < 0 || index > (size - 1))
                return -1;
        
            ListNode *cur = dummyhead -> next;       // 注意查询时cur指向的是当前节点，所以开始时从虚拟头节点后开始
            while(index){
                cur = cur -> next;
                index --;
            }
            return cur -> val;
        }

        // 添加新的头节点
        void addAtHead(int val) {
            ListNode *newnode = new ListNode(val);

            newnode -> next = dummyhead -> next;
            dummyhead -> next = newnode;

            size += 1;
        }
        
        // 添加新的尾节点 
        void addAtTail(int val) {
            ListNode *cur = dummyhead;

            while(cur -> next != nullptr)
                cur = cur -> next;
        
            ListNode *newnode = new ListNode(val);
            cur -> next = newnode;

            size += 1;
        }

        // 在指定位置添加新节点
        void addAtIndex(int index, int val) {
            if(index > size) return;                    // index大于size甚至已经超出链表的尾部（此处要谨慎debug）
            if(index < 0) index = 0;
            ListNode *cur = dummyhead;
            ListNode *newnode = new ListNode(val);
            
            // 循环量要代入一些极端值进行判断
            while(index){
                cur = cur -> next;
                index --;
            }
            newnode -> next = cur -> next;
            cur -> next = newnode;
            
            size += 1;
        }

        // 在指定位置删除节点
        void deleteAtIndex(int index) {
            if(index >= 0 && index < size){
                ListNode *cur = dummyhead;
            
                while(index){
                    cur = cur -> next;
                    index --;
                }

                ListNode *tmp = cur -> next;
                cur -> next = tmp -> next;
                // cur -> next = cur -> next -> next;
                delete tmp;
                tmp = nullptr;
                size -= 1;
            }
        }

        // 打印链表
        void printList(){
            ListNode *cur = dummyhead;
            while(cur -> next != nullptr){
                cur = cur -> next;
                cout << cur -> val << " ";
            }
        }
};

// 测试+debug
int main()
{
    MyLinkedList list;
    list.addAtHead(7);
    list.addAtHead(2);
    list.addAtHead(1);
    list.addAtIndex(3,0);
    list.deleteAtIndex(2);
    list.addAtHead(6);
    list.addAtTail(4);
    list.get(4);
    list.addAtHead(4);
    list.addAtIndex(5,0);
    list.addAtHead(6);
    list.printList();
    return 0;
}