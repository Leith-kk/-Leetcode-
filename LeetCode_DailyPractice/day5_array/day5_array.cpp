// leetcode 27 （相当于实现erase内置函数）
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // 近似暴力解法（比暴力解法好一丢丢，因为本题目不管顺序）
    int removeElement(vector<int>& nums, int val) {
        int a[100];                                  // 用来记录数组中val对应的下标
        int cout = 0;                                // 用来计数数组中val出现的次数
        int sub = nums.size();                       // 求出数组的长度便于之后迭代

        // 记录数组中val所在下标
        for(int i = 0; i < nums.size();++i){         
            if(nums[i] == val){
                a[i] = 0;
                ++cout;
            }
            else{
                a[i] = 1;
            }
        }

        // 将nums数组中末尾不是val的数向前提填补val的空位，覆盖=删去（有双指针那味了！改一改就是双指针）
        for(int i = 0;i < nums.size();++i){
            if(nums[i] == val){
                for(int j = sub - 1;j >= 0;--j){       // 此处用sub迭代很关键
                    if(a[j] == 1){
                        nums[i] = nums[j];
                        sub = j;
                        break;
                    }
                }
            }
        }
        return nums.size() - cout;
    }

    // 重点：双指针法，最多遍历两遍数组
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;                                  // 左指针移动慢，为待赋值的元素
        for (int right = 0; right < n; right++) {      // right指针移动快，为正在处理的元素
            if (nums[right] != val) {
                nums[left] = nums[right];              // right指向元素为val，right就后移一位处理下一个元素，right指向非val元素，就把它赋值给left
                left++;
            }
        }
        return left;
    }  

    // 针对此题的双指针优化，最多遍历一遍数组
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;              // left在首，right在尾 
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                right--;                                    // left与right向中间移动
            } else {
                left++;
            }
        }
        return left;
    }
};