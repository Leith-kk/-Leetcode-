// leeetcode 102 二叉树的层序遍历
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义树节点
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode () : val(0), left(nullptr), right(nullptr){}
    TreeNode (int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode (int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
}

class Solution{
public:
    // 使用队列实现层序遍历
    vector<vector<int>> levelOrder_1(TreeNode* root) {
        vector<vector<int>> result;             // 每一层的节点值存储为一个vector数组
        if(root == nullptr) return result;
        queue<TreeNode*> q;                     // 用于存储每一层的节点
        q.push(root);

        while(!q.empty()){
            int size = q.size();                 // 当前层的节点个数
            vector<int> v;
            for(int i = 0; i < size; ++i){
                TreeNode *node = q.front();
                v.push_back(node->val);
                q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);

                // 实现思路：
                // 1. 首先将根节点入队
                // 2. 当队列不为空时，取出队列中的节点，将节点的值存储到vector中
                // 3. 将节点的左右子节点入队
                // 4. 重复2-3步骤，直到队列为空
            }
            result.push_back(v);
        }

        return result;
    }

    // 使用递归实现层序遍历
    void order(TreeNode *cur, vector<vector<int>> &result, int level){
        if(cur == nullptr) return ;                                   // 递归截止条件
        if(result.size() == level) result.push_back(vector<int>());   // 若当前层不存在，则创建一个新的vector
        result[level].push_back(cur -> val);      // 将当前节点的值存储到对应层的vector中
        order(cur -> left, result, level + 1);    // 递归左子树
        order(cur -> right, result, level + 1);   // 递归右子树
    }

    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> result;
        if(root == nullptr) return result;
        order(root, result, 0);

        return result;
    }
};
