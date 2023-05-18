#include <bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height) 
{
    int n = height.size();

    int res = 0;
    int left = 0;
    int right = n-1;
    while(left<right)
    {
        res = max(res, (right-left) * min(height[left], height[right]) );
        if(height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return res;
}