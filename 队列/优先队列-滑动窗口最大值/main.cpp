#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PAIR;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> res;

    /* 创建初始值   */
    int n = nums.size();
    int start = 0;
    int end   = start + k - 1;
    priority_queue<PAIR, vector<PAIR>> q;

    /* 存入元素 */
    for(int ii=start; ii<end; ii++)
        q.push({nums[ii], ii});

    PAIR cur;
    while(end < n)
    {
        /* 向队列存入当前end位置元素            */
        q.push({nums[end], end});

        /* 从队列中取出一个在start-end区间的数  */
        while(!q.empty())
        {
            cur = q.top();
            if(cur.second >= start && cur.second <= end)
            {
                break;
            }
            else
            {
                q.pop();
            }
        }
        res.push_back(nums[cur.second]);

        start++;
        end++;
    }

    return res;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ret = maxSlidingWindow(nums, k);
    for(auto r:ret)
        cout << r << " ";
    cout << endl;

    return 0;
}