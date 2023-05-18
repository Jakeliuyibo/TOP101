class Solution {
public:


    vector<vector<int>> threeSum(vector<int>& nums) 
    {   
        vector<vector<int>> res;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int ii=0; ii<n; ii++)
        {
            if(ii>0 && nums[ii]==nums[ii-1]) continue;

            int left  = ii+1;
            int right = n-1;
            int target = 0 - nums[ii];
            
            while(left<right)
            {
                if(nums[left]+nums[right] == target)
                {
                    res.push_back({nums[ii], nums[left], nums[right]});

                    /* 对left和right去重    */
                    while(left<right && nums[left]  == nums[left+1])    left++;
                    while(left<right && nums[right] == nums[right-1])   right--;

                    left++;
                    right--;
                }
                else if(nums[left]+nums[right] < target)
                {   
                    left++;
                }
                else
                {
                    right--;
                }

            }
        }
        
        return res;
    }
};