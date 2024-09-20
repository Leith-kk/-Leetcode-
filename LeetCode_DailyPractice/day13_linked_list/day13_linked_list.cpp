// leetcode 203

struct Node
{
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}                // 默认构造函数
    Node(int x) : val(x), next(nullptr) {}           // 使用带一个参数的构造函数创建节点
    Node(int x, Node *next) : val(x), next(next) {}  // 使用带两个参数的构造函数创建节点

    // nullptr专门表示空指针，NULL表示一个整数，使用NULL可能会在函数重载时遇到无法判别指针还是整数的问题
};

// 不用虚拟头节点
class Solution {
public:
    Node* removeElements(Node* head, int val) {
        // 链表头节点在内的前几个节点为待删除节点，注意使用while
        while(head != NULL && head -> val == val)
        {
            Node *n = head;
            head = head -> next;
            delete n;                                   // C++需要手动释放内存，python不需要
        }
        
        // 删除非头节点
        Node *cur = head;
        while(cur != NULL && cur -> next != NULL)
        {
            if(cur -> next -> val == val){
                Node *n = cur -> next;
                cur -> next = cur -> next -> next;
                delete n;
            }
            else{
                cur = cur -> next;
            }
        }
        
        return head;
    }
};


// 使用虚拟头节点
class Solution {
public:
    Node* removeElements(Node* head, int val) {
        // 定义虚拟头节点
        Node *dummyhead = new Node(0);
        dummyhead -> next = head;

        // 只需执行一种循环删除操作
        Node *cur = dummyhead;
        while(cur != nullptr && cur -> next != nullptr)
        {
            if(cur -> next -> val == val){
                Node *n = cur -> next;
                cur -> next = cur -> next -> next;
                delete n;
            }
            else{
                cur = cur -> next;
            }
        }
        
        return dummyhead -> next;
    }
};
