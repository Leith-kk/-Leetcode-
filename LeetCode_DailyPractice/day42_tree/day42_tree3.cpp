// leetcode 94 二叉树的中序遍历
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义树节点
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

// 使用递归的方法
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

    // 再次明确递归三要素：
    // 1、确定递归函数的参数和返回值：中序遍历参数就是要处理的节点，返回值就是要返回的结果
    // 2、确定终止条件：当前节点为空时返回
    // 3、确定单层递归逻辑：先递归左子树，当前节点值加入结果，再递归右子树
};

// 使用迭代的方法，底层实现是栈
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

        // 思路解析：中序遍历是从根节点开始由上向下访问节点，一直到树底端最左侧由下向上处理节点
        // 1、首先判断当前处理的节点是否为空，不为空则将当前节点压入栈中，并将当前节点设置为当前节点的左子节点
        // 2、一路向左子树遍历，直到当前节点为空，此时栈顶元素就是最左叶节点
        // 3、取出栈顶元素，将栈顶元素的值加入result，将当前访问节点设置为栈顶元素的右子节点
        // 4、右子节点也为叶节点，重复步骤2，3，该节点左侧为空，栈顶元素即为该节点，将该节点出栈，将其值加入result，右节点为空，继续出栈到叶节点的父节点
        // 5、该父节点的左子树已经遍历完毕，将该父节点出栈，将其值加入result，将当前节点设置为该父节点的右子节点
        // 6、重复步骤2，3，4，5，直到栈为空，遍历结束
    }
};

// 通用解法，底层实现是栈
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
                if(cur -> right) st.push(cur -> right);// 不要空指针入栈，不要影响后续的处理
                st.push(cur);
                st.push(nullptr);                      // 作为标记，表示该节点作为下次处理的节点
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