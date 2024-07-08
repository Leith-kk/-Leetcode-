// leetcode 35
class Solution {
public:
    int searchInsert(int *nums, int target) {
        int left = 0, right = sizeof(nums)/sizeof(int) - 1;
        int mid = 0;

        if(nums[left] > target){                 // �Բ��ֲ������ݿ�����ǰ����
            return 0;
        }
        if(nums[right] < target){
            return right + 1;
        }

        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;                            // left��Ӧ����Ŀ�����λ��
    }
};