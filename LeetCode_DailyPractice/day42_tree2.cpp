// leetcode 145 二叉树的后序遍历
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>  // 包含reverse函数

using namespace std;

// 树的节点
struct TreeNode{
    int val;
    TreeNode* left;;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

// 方法1：递归
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

    // 递归的思路：
    // 1、明确递归函数的参数，包括当前节点指针cur和存放结果的数组res
    // 2、递归函数的终止条件，即cur为空
    // 3、递归函数的递归过程，先递归左子树，再递归右子树，最后将当前节点的值加入到结果数组中
};

// 方法2：迭代，使用栈
// 后序遍历是左右中，将前序遍历的中左右改为中右左，再将结果反转即可
class Solution_2{
public:
    vector<int> PostorderTraversal_2(TreeNode *root){
        vector<int> result;
        if(root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode *cur = st.top();  // 每次都是取栈顶元素
            if(cur != nullptr){
                result.push_back(cur -> val);
                st.pop();   
                st.push(cur -> left);  
                st.push(cur -> right);
            }
            else st.pop();          // 为了保证栈顶元素不为空，需要将空节点弹出，一般是访问到叶节点时出现空节点
        }
        reverse(result.begin(), result.end()); // 将结果反转
        return result;
    }
};

// 方法3：迭代，使用栈
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
                st.push(nullptr);                      // 作为标记，表示该节点作为下次处理的节点
                if(cur -> right) st.push(cur -> right);// 不要空指针入栈，不要影响后续的处理
                if(cur -> left) st.push(cur -> left);  // 左右指针入栈顺序不能颠倒,因为栈是先进后出
            }
            else{
                st.pop();                       // 空指针是标记，表示栈里面的下一个节点是要处理的节点
                TreeNode *node = st.top();      // 将要处理的节点取出来
                result.push_back(node -> val);
                st.pop();                       // 中间节点处理完毕，弹出
            }
        }
    }
};

// 测试
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