// leetcode 283
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 使用快慢指针（也叫左右指针）
    void moveZeroes(vector<int>& nums){
        int low = 0, fast = 0;             // 注意：快指针为当前处理元素，慢指针为当前待赋值位置
        while(fast < nums.size()){
            if(nums[fast] == 0){           // 只需要处理快指针所指向的值即可
                    ++ fast;
            }else{
                nums[low] = nums[fast];
                ++ low;
                ++ fast;
            }
        }

        // 将最后一次low-fast之间的所有元素修改为0
        for(int i = low; i < fast; ++ i){
            nums[i] = 0;
        }
    }

    // 快速排序法
    void moveZeroes(vector<int>& nums){
        if(nums.size() == 0) {
			return;
		}

		//两个指针i和j,i比j快
		int j = 0;
		for(int i = 0;i < nums.size();i++) {
			//当前元素!=0，就把其交换到左边，等于0的交换到右边
			if(nums[i]!=0) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j++] = tmp;
			}
		}
	}

};
