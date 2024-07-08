// leetcode 283
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // ʹ�ÿ���ָ�루Ҳ������ָ�룩
    void moveZeroes(vector<int>& nums){
        int low = 0, fast = 0;             // ע�⣺��ָ��Ϊ��ǰ����Ԫ�أ���ָ��Ϊ��ǰ����ֵλ��
        while(fast < nums.size()){
            if(nums[fast] == 0){           // ֻ��Ҫ�����ָ����ָ���ֵ����
                    ++ fast;
            }else{
                nums[low] = nums[fast];
                ++ low;
                ++ fast;
            }
        }

        // �����һ��low-fast֮�������Ԫ���޸�Ϊ0
        for(int i = low; i < fast; ++ i){
            nums[i] = 0;
        }
    }

    // ��������
    void moveZeroes(vector<int>& nums){
        if(nums.size() == 0) {
			return;
		}

		//����ָ��i��j,i��j��
		int j = 0;
		for(int i = 0;i < nums.size();i++) {
			//��ǰԪ��!=0���Ͱ��佻������ߣ�����0�Ľ������ұ�
			if(nums[i]!=0) {
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j++] = tmp;
			}
		}
	}

};
