#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

bool binarySearch(vector<int> array, int target)
{
    /* 二分查找当前行   */
    int left  = 0;
    int right = array.size() - 1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if(array[mid] == target) return true;
        if (array[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool find(vector<vector<int>> array, int target)
{
    if(array[0].size() == 0) return false;
    printf("array size=%d\n", array.size());

    /* 求解row范围  */
    int row = 0;
    for(; row<array.size();row++)
    {
        if(array[row][0] > target)
        {
            break;
        }
    }

    /* 二分查找遍历数组 */
    for(int ii=0; ii<row; ii++)
    {
        bool ret = binarySearch(array[ii], target);
        if(ret == true)
            return true;
    }

    return false;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<vector<int>> arr= {{1,2,3},{4,5,6}};
    int target = 7;

    cout << find(arr, target) << endl;

    return 0;
}