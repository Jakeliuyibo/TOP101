class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();

        /* 排序     */
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(int ii=0; ii<n; ii++)
        {
            if(ii>0 && nums[ii]==nums[ii-1])    continue;

            for(int jj=ii+1; jj<n; jj++)
            {
                if(jj>ii+1 && nums[jj]==nums[jj-1])    continue;

                int left  = jj+1;
                int right = n-1;
                long tar = (long)target - (long)nums[ii] - (long)nums[jj];
                while(left<right)
                {
                    // printf("curr(%d,%d) (%d,%d)\n", ii, jj, left, right);
                    long cur = nums[left]+nums[right];
                    if(cur == tar)
                    {
                        res.push_back({nums[ii], nums[jj], nums[left], nums[right]});

                        /* 去重 */
                        while(left<right && nums[left]==nums[left+1])   left++;
                        while(left<right && nums[right]==nums[right-1]) right--; 
                        left++;
                        right--;
                    }
                    else if(cur < tar)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }

                }
            }
        }
        return res;
    }
};