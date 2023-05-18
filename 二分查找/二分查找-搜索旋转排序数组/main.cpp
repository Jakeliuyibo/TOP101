class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();

        /* 二分查找 */
        int left  = 0;
        int right = n-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            // printf("当前left=%d right=%d mid=%d nums[mid]=%d \n", left, right, mid, nums[mid]);

            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[0])     // mid左半边有序
            {
                if(nums[0] <= target && target < nums[mid])
                    right = mid-1;
                else
                    left  = mid+1;
            }
            else                        // mid右半边有序
            {
                if(nums[mid]<target && target<=nums[n-1])
                    left  = mid+1;
                else
                    right = mid-1;
            }
        }

        return -1;
    }
};