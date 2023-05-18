#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int, vector<int>> pq;
    for(int ii=0; ii<nums.size(); ii++)
    {
        pq.push(nums[ii]);
    }    
    
    int ret = 0;
    k--;
    while(k--)
    {
        pq.pop();
    }

    return pq.top();
}

int main()
{
    vector<int> nums = {3,2,1,5,34,4,3,45,46,4,45};
    int k =3;
    cout << findKthLargest(nums, k) << endl;

    return 0;
}