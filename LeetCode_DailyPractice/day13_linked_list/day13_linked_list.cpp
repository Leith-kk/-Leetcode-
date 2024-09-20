// leetcode 203

struct Node
{
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}                // Ĭ�Ϲ��캯��
    Node(int x) : val(x), next(nullptr) {}           // ʹ�ô�һ�������Ĺ��캯�������ڵ�
    Node(int x, Node *next) : val(x), next(next) {}  // ʹ�ô����������Ĺ��캯�������ڵ�

    // nullptrר�ű�ʾ��ָ�룬NULL��ʾһ��������ʹ��NULL���ܻ��ں�������ʱ�����޷��б�ָ�뻹������������
};

// ��������ͷ�ڵ�
class Solution {
public:
    Node* removeElements(Node* head, int val) {
        // ����ͷ�ڵ����ڵ�ǰ�����ڵ�Ϊ��ɾ���ڵ㣬ע��ʹ��while
        while(head != NULL && head -> val == val)
        {
            Node *n = head;
            head = head -> next;
            delete n;                                   // C++��Ҫ�ֶ��ͷ��ڴ棬python����Ҫ
        }
        
        // ɾ����ͷ�ڵ�
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


// ʹ������ͷ�ڵ�
class Solution {
public:
    Node* removeElements(Node* head, int val) {
        // ��������ͷ�ڵ�
        Node *dummyhead = new Node(0);
        dummyhead -> next = head;

        // ֻ��ִ��һ��ѭ��ɾ������
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
