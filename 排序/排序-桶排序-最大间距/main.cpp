class Solution 
{
public:

    struct bucket
    {
        int min;
        int max;
        bool used;
        bucket() : min(INT_MAX), max(INT_MIN), used(false) {}
    };

    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<2)
            return 0;

        // 确定桶个数和桶高度
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(auto n:nums)
        {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        int heightBucket = max(1, (maxNum - minNum) / (n-1));
        int numBucket    = (maxNum - minNum) / heightBucket + 1;

        // 遍历数组将数加入桶
        vector<bucket> bucket_array(numBucket);
        for(int idx=0; idx<n; idx++)
        {
            int bucket_idx = (nums[idx] - minNum) / heightBucket;

            bucket_array[bucket_idx].min  = min(bucket_array[bucket_idx].min, nums[idx]);
            bucket_array[bucket_idx].max  = max(bucket_array[bucket_idx].max, nums[idx]);
            bucket_array[bucket_idx].used = true;
        }

        // 遍历桶，计算桶之间的最大差值
        int res = 0;
        int last_max = bucket_array[0].max;
        for(int idx=1; idx<bucket_array.size(); idx++)
        {
            if(bucket_array[idx].used)
            {
                int cur_min = bucket_array[idx].min;
                res = max(res, cur_min - last_max);
                last_max = bucket_array[idx].max;
            }
        }
        return res;
    }



};