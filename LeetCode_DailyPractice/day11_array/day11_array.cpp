// leetcode 59
// 关键：循环不变量 左开右闭区间

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    vector<vector<int>> generateMatrix(int n) {
        // vector<vector<int>> res;：这行代码声明了一个名为 res 的二维向量，其中每个元素本身也是一个向量。
        // res(n, vector<int>(n, 0));：这部分代码初始化了 res，使其包含 n 个向量，每个向量又包含 n 个元素，并且所有这些元素都被初始化为 0。
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int k = n / 2;                                 // 定义循环次数，n为奇数时，n-2k-1=0，n为偶数时，n-2k=0
        int startx = 0, starty = 0;                    // 每行的起始位置
        int mid = n / 2;                               // 若n为奇数，需要对最中间的位置单独赋值
        int offset = 1;                                // 每次行/列尾向内避免溢出的量
        int i = 0, j = 0;
        int cout = 0;

        while(k--){
            for(j = starty; j < n - offset; ++j)
                res[startx][j] = ++cout;
            for(i = startx; i < n - offset; ++i)
                res[i][j] = ++cout;
            for(;j > starty; --j)
                res[i][j] = ++cout;
            for(;i > startx; --i)
                res[i][j] = ++cout;

            ++startx;                                  // 更新每层循环的起始位置和向内避免溢出量
            ++starty;
            ++offset;
        }

        if(n % 2 == 1)
            res[mid][mid] = ++cout;
        
        return res;
    }
};
