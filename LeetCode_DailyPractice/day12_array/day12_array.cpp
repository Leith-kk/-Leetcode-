// leetcode 54
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {  
        vector <int> ans;     // C++中vector是一个向量，相比数组其长度可以自由改变，此处ans为一个空向量

        // 若matrix为空，则直接返回空向量
        if(matrix.empty()) return ans;

        // 取数组的上下左右边界
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(true){
            // 第一行完整读取，读取完更新当前上边界到下一行，避免重复读取
            for(int j = left; j <= right; ++j) ans.push_back(matrix[up][j]);
            if(++up > down) break;

            // 最后一列读取最上面元素以外的其他元素，读取完更新当前右边界，避免重复读取
            for(int i = up; i <= down; ++i) ans.push_back(matrix[i][right]);
            if(--right < left) break;
            
            // 最后一行读取最右侧元素以外的其他元素，读取后更新当前下边界，避免重复读取
            for(int j = right; j >= left; --j) ans.push_back(matrix[down][j]);
            if(--down < up) break;

            // 第一列读取顶端和底端以外的其他元素，读取后更新当前左边界，避免重复读取
            for(int i = down; i >= up; --i) ans.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution test;
    for(size_t i = 0; i < test.spiralOrder(matrix).size(); ++i)
        cout << test.spiralOrder(matrix)[i] << " ";
    
    return 0;
}
