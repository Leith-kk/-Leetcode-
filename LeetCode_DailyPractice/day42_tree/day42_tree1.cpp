// leetcode 144 ��������ǰ������������ң�
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // nullptr��C++11�����ԣ���ʾ��ָ�룬NULL��C++98�����ԣ���ʾ��ָ��
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ʹ�õݹ�ķ���
class Solution_1{
public:
    void Traversal(TreeNode *cur, vector<int> &res){
        if(cur == NULL) return;
        res.push_back(cur->val);
        Traversal(cur->left, res);      // res�����ã��൱�ڴ��ݵ��ǵ�ַ�����Եݹ����ʱ��res��ͬһ����ַ
        Traversal(cur->right, res);
    }

    vector<int> preorderTraversal_1(TreeNode* root){
        vector<int> result;
        Traversal(root, result);
        return result;
    }

    // �ݹ���Ҫ�أ�
    // 1.ȷ���ݹ麯���Ĳ����ͷ���ֵ����������Ҫ����Ľڵ㣬����ֵ����Ҫ���صĽ��
    // 2.ȷ����ֹ��������ǰ�ڵ�Ϊ��ʱ����
    // 3.ȷ������ݹ��߼�����ǰ�ڵ�ֵ���������ȵݹ����������ٵݹ�������
};

// ʹ�õ����ķ������ײ�ʵ����ջ
class Solution_2{
public:
    vector<int> preorderTraversal_2(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *node = st.top();
            if(node != nullptr){
                result.push_back(node->val);
                st.pop();
                st.push(node->right);
                st.push(node->left);
            }
            else{
                st.pop();
            }
        }

        return result;

        // ջ���ص����Ƚ�����������Ƚ�������ѹջ���ٽ�������ѹջ
        // ˼·������ǰ������Ӷ�����ʼ���ϵ��·��ʽڵ㣬�Ӷ�����ʼ���ϵ��´���ڵ㣬����˳���봦��˳����ͬ
        // 1.�����ڵ�ѹջ
        // 2.����ջ��Ԫ�أ���ֵ������
        // 3.��������ѹջ
        // 4.��������ѹջ
        // 5.�ظ�2-4����
        // ��ǰ���������ʱ����ǰ����ڵ㣨node->val����Ϊ��ǰ���ʽڵ�node�������������ͬ
    }
};

// ����ͳһд�����ײ�ʵ��Ҳ��ջ��
class Solution_3{
public:
    vector<int> preorderTraversal_3(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *cur = st.top();
            if(cur != nullptr){
                st.pop();
                if(cur -> right) st.push(cur -> right);// ��Ҫ��ָ����ջ����ҪӰ������Ĵ���
                if(cur -> left) st.push(cur -> left);  // ����ָ����ջ˳���ܵߵ�,��Ϊջ���Ƚ����
                st.push(cur);
                st.push(nullptr);                      // ��Ϊ��ǣ���ʾ�ýڵ���Ϊ�´δ���Ľڵ�
            }
            else{
                st.pop();                       // ��ָ���Ǳ�ǣ���ʾջ�������һ���ڵ���Ҫ����Ľڵ�
                TreeNode *node = st.top();      // ��Ҫ����Ľڵ�ȡ����
                result.push_back(node -> val);
                st.pop();                       // �м�ڵ㴦����ϣ�����
            }
        }
    }
};

// ����
int main(){
    // ����������
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution_3 s;
    // vector<int> result = s.preorderTraversal_1(root);
    // vector<int> result = s.preorderTraversal_2(root);
    vector<int> result = s.preorderTraversal_3(root);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    return 0;
}
