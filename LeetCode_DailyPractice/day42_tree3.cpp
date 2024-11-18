// leetcode 94 ���������������
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// �������ڵ�
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

// ʹ�õݹ�ķ���
class Solution_1{
public:
    void Traversal(TreeNode *cur, vector<int> &res){
        if(cur == nullptr) return;
        Traversal(cur -> left, res);
        res.push_back(cur -> val);
        Traversal(cur -> right, res);
    }

    vector<int> InorderTraversal_1(TreeNode *root){
        vector<int> result;
        Traversal(root, result);

        return result;
    }

    // �ٴ���ȷ�ݹ���Ҫ�أ�
    // 1��ȷ���ݹ麯���Ĳ����ͷ���ֵ�����������������Ҫ����Ľڵ㣬����ֵ����Ҫ���صĽ��
    // 2��ȷ����ֹ��������ǰ�ڵ�Ϊ��ʱ����
    // 3��ȷ������ݹ��߼����ȵݹ�����������ǰ�ڵ�ֵ���������ٵݹ�������
};

// ʹ�õ����ķ������ײ�ʵ����ջ
class Solution_2{
public:
    vector<int> InorderTraversal_2(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> st;
        TreeNode *cur = root;

        while(!st.empty()){
            while(cur != nullptr){
                st.push(cur);
                cur = cur -> left;
            }
            cur = st.top();
            st.pop();
            result.push_back(cur -> val);
            cur = cur -> right;
        }

        // ˼·��������������ǴӸ��ڵ㿪ʼ�������·��ʽڵ㣬һֱ�����׶�������������ϴ���ڵ�
        // 1�������жϵ�ǰ����Ľڵ��Ƿ�Ϊ�գ���Ϊ���򽫵�ǰ�ڵ�ѹ��ջ�У�������ǰ�ڵ�����Ϊ��ǰ�ڵ�����ӽڵ�
        // 2��һ·��������������ֱ����ǰ�ڵ�Ϊ�գ���ʱջ��Ԫ�ؾ�������Ҷ�ڵ�
        // 3��ȡ��ջ��Ԫ�أ���ջ��Ԫ�ص�ֵ����result������ǰ���ʽڵ�����Ϊջ��Ԫ�ص����ӽڵ�
        // 4�����ӽڵ�ҲΪҶ�ڵ㣬�ظ�����2��3���ýڵ����Ϊ�գ�ջ��Ԫ�ؼ�Ϊ�ýڵ㣬���ýڵ��ջ������ֵ����result���ҽڵ�Ϊ�գ�������ջ��Ҷ�ڵ�ĸ��ڵ�
        // 5���ø��ڵ���������Ѿ�������ϣ����ø��ڵ��ջ������ֵ����result������ǰ�ڵ�����Ϊ�ø��ڵ�����ӽڵ�
        // 6���ظ�����2��3��4��5��ֱ��ջΪ�գ���������
    }
};

// ͨ�ýⷨ���ײ�ʵ����ջ
class Solution_3{
public:
    vector<int> InorderTraversal_3(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *cur = st.top();
            if(cur != nullptr){
                st.pop();
                if(cur -> right) st.push(cur -> right);// ��Ҫ��ָ����ջ����ҪӰ������Ĵ���
                st.push(cur);
                st.push(nullptr);                      // ��Ϊ��ǣ���ʾ�ýڵ���Ϊ�´δ���Ľڵ�
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

    Solution_1 s1;
    vector<int> result_1 = s1.InorderTraversal_1(root);
    for(int i = 0; i < result_1.size(); i++){
        cout << result_1[i] << " ";
    }
    cout << endl;

    Solution_2 s2;
    vector<int> result_2 = s2.InorderTraversal_2(root);
    for(int i = 0; i < result_2.size(); i++){
        cout << result_2[i] << " ";
    }
    cout << endl;

    Solution_3 s3;
    vector<int> result_3 = s3.InorderTraversal_3(root);
    for(int i = 0; i < result_3.size(); i++){
        cout << result_3[i] << " ";
    }
    cout << endl;

    return 0;
}