// leetcode 144 二叉树的前序遍历（中左右）
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // nullptr是C++11的特性，表示空指针，NULL是C++98的特性，表示空指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 使用递归的方法
class Solution_1{
public:
    void Traversal(TreeNode *cur, vector<int> &res){
        if(cur == NULL) return;
        res.push_back(cur->val);
        Traversal(cur->left, res);      // res是引用，相当于传递的是地址，所以递归调用时，res是同一个地址
        Traversal(cur->right, res);
    }

    vector<int> preorderTraversal_1(TreeNode* root){
        vector<int> result;
        Traversal(root, result);
        return result;
    }

    // 递归三要素：
    // 1.确定递归函数的参数和返回值：参数就是要处理的节点，返回值就是要返回的结果
    // 2.确定终止条件：当前节点为空时返回
    // 3.确定单层递归逻辑：当前节点值加入结果，先递归左子树，再递归右子树
};

// 使用迭代的方法，底层实现是栈
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

        // 栈的特点是先进后出，所以先将右子树压栈，再将左子树压栈
        // 思路分析：前序遍历从顶部开始由上到下访问节点，从顶部开始由上到下处理节点，访问顺序与处理顺序相同
        // 1.将根节点压栈
        // 2.弹出栈顶元素，将值加入结果
        // 3.将右子树压栈
        // 4.将左子树压栈
        // 5.重复2-4步骤
        // 在前序遍历迭代时，当前输出节点（node->val）即为当前访问节点node，与中序遍历不同
    }
};

// 迭代统一写法（底层实现也是栈）
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
                if(cur -> right) st.push(cur -> right);// 不要空指针入栈，不要影响后续的处理
                if(cur -> left) st.push(cur -> left);  // 左右指针入栈顺序不能颠倒,因为栈是先进后出
                st.push(cur);
                st.push(nullptr);                      // 作为标记，表示该节点作为下次处理的节点
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
    // 创建二叉树
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
