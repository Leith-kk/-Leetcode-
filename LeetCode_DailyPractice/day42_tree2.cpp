// leetcode 145 �������ĺ������
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>  // ����reverse����

using namespace std;

// ���Ľڵ�
struct TreeNode{
    int val;
    TreeNode* left;;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

// ����1���ݹ�
class Solution_1{
public:
    void Traversal(TreeNode *cur, vector<int> &res){
        if(cur == nullptr) return;
        Traversal(cur -> left, res); 
        Traversal(cur -> right, res);
        res.push_back(cur -> val);
    }

    vector<int> PostorderTraversal_1(TreeNode *root){
        vector<int> result;
        Traversal(root, result);

        return result;
    }

    // �ݹ��˼·��
    // 1����ȷ�ݹ麯���Ĳ�����������ǰ�ڵ�ָ��cur�ʹ�Ž��������res
    // 2���ݹ麯������ֹ��������curΪ��
    // 3���ݹ麯���ĵݹ���̣��ȵݹ����������ٵݹ�����������󽫵�ǰ�ڵ��ֵ���뵽���������
};

// ����2��������ʹ��ջ
// ��������������У���ǰ������������Ҹ�Ϊ�������ٽ������ת����
class Solution_2{
public:
    vector<int> PostorderTraversal_2(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *cur = st.top();  // ÿ�ζ���ȡջ��Ԫ��
            if(cur != nullptr){
                result.push_back(cur -> val);
                st.pop();   
                st.push(cur -> left);  
                st.push(cur -> right);
            }
            else st.pop();          // Ϊ�˱�֤ջ��Ԫ�ز�Ϊ�գ���Ҫ���սڵ㵯����һ���Ƿ��ʵ�Ҷ�ڵ�ʱ���ֿսڵ�
        }
        reverse(result.begin(), result.end()); // �������ת
        return result;
    }
};

// ����3��������ʹ��ջ
class Solution_3{
public:
    vector<int> PostorderTraversal_3(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *cur = st.top();
            if(cur != nullptr){
                st.pop();
                st.push(cur);
                st.push(nullptr);                      // ��Ϊ��ǣ���ʾ�ýڵ���Ϊ�´δ���Ľڵ�
                if(cur -> right) st.push(cur -> right);// ��Ҫ��ָ����ջ����ҪӰ������Ĵ���
                if(cur -> left) st.push(cur -> left);  // ����ָ����ջ˳���ܵߵ�,��Ϊջ���Ƚ����
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
    TreeNode *root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> left = new TreeNode(3);
    root -> right -> right = new TreeNode(4);

    Solution_1 s1;
    vector<int> result = s1.PostorderTraversal_1(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    Solution_2 s2;
    result = s2.PostorderTraversal_2(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    Solution_3 s3;
    result = s3.PostorderTraversal_3(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}