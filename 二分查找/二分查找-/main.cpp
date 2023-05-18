#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型vector 
 * @param target int整型 
 * @return int整型
 */
int search(vector<int>& nums, int target) 
{
    int left    = 0;
    int right   = nums.size()-1;

    while(left<=right)
    {
        int mid     = (left+right)/2;
        printf("curr left=%d mid=%d right=%d\n",left,mid,right);

        if(target == nums[mid]) return mid;
        else if(target < nums[mid])
        {
            right = mid-1;
        }
        else if(target > nums[mid])
        {
            left  = mid+1;
        }
    }

    return -1;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> arr= {1,2,3,4,5};
    int target = 2;

    cout << search(arr, target) << endl;

    return 0;
}