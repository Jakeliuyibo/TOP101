#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
{
    vector<vector<int>> res;

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;
    for(int ii=1; ii<n; ii++)
    {
        int curr = abs(arr[ii] - arr[ii-1]);
        if(curr < min_diff)
        {
            min_diff = curr;
            res.clear();
            res.push_back({arr[ii-1],arr[ii]});
        }
        else if(curr == min_diff)
        {
            res.push_back({arr[ii-1],arr[ii]});
        }
    }

    /*  输出处理    */
    return res;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    /* 输入处理     */

    vector<int> nums1 = {7,11,13}; 
    vector<int> nums2 = {1,1,1}; 

    cout << maximumsSplicedArray(nums1, nums2) << endl;

    return 0;
}