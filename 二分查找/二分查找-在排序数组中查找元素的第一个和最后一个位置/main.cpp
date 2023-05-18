class Solution {
public:

    /* 二分查找 */
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left=0, right=n-1;

        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left  = mid + 1;
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int ret = search(nums, target);
        if(ret == -1)
            return {-1,-1};

        /*向两边查找    */
        int left  = ret;
        int right = ret;
        while(left>0 && nums[left]==nums[left-1])
        {
            left--;
        }
        while(right<n-1 && nums[right]==nums[right+1])
        {
            right++;
        }

        return {left,right};
    }
};