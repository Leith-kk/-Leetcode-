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
        // �๹�캯�� 
        MyLinkedList() {
            this->size = 0;
            this->dummyhead = new ListNode(0);       //����ͷ�ڵ�
        }
        
        // �����±��ȡ��ֵ(�±��0��ʼ)
        int get(int index) {
            if(index < 0 || index > (size - 1))
                return -1;
        
            ListNode *cur = dummyhead -> next;       // ע���ѯʱcurָ����ǵ�ǰ�ڵ㣬���Կ�ʼʱ������ͷ�ڵ��ʼ
            while(index){
                cur = cur -> next;
                index --;
            }
            return cur -> val;
        }

        // ����µ�ͷ�ڵ�
        void addAtHead(int val) {
            ListNode *newnode = new ListNode(val);

            newnode -> next = dummyhead -> next;
            dummyhead -> next = newnode;

            size += 1;
        }
        
        // ����µ�β�ڵ� 
        void addAtTail(int val) {
            ListNode *cur = dummyhead;

            while(cur -> next != nullptr)
                cur = cur -> next;
        
            ListNode *newnode = new ListNode(val);
            cur -> next = newnode;

            size += 1;
        }

        // ��ָ��λ������½ڵ�
        void addAtIndex(int index, int val) {
            if(index > size) return;                    // index����size�����Ѿ����������β�����˴�Ҫ����debug��
            if(index < 0) index = 0;
            ListNode *cur = dummyhead;
            ListNode *newnode = new ListNode(val);
            
            // ѭ����Ҫ����һЩ����ֵ�����ж�
            while(index){
                cur = cur -> next;
                index --;
            }
            newnode -> next = cur -> next;
            cur -> next = newnode;
            
            size += 1;
        }

        // ��ָ��λ��ɾ���ڵ�
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

        // ��ӡ����
        void printList(){
            ListNode *cur = dummyhead;
            while(cur -> next != nullptr){
                cur = cur -> next;
                cout << cur -> val << " ";
            }
        }
};

// ����+debug
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