#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


int minNumberInRotateArray(vector<int> rotateArray) 
{
    if (rotateArray.size() == 1) return rotateArray[0];
    if (rotateArray.size() == 2) return min(rotateArray[0], rotateArray[1]);

    int left  = 0;
    int right = rotateArray.size() - 1;
    while(left < right)
    {
        int mid = (left+right)/2;

        if(rotateArray[mid]>rotateArray[right])
        {
            left = mid;
        }
        else if(rotateArray[mid]<rotateArray[right])
        {
            right = mid;
        }
        else
        {
            right = right -1;
        }

    }

    return right;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    vector<int> arr= {3,4,5,6,7,8,9,1,2};
    cout << minNumberInRotateArray(arr) << endl;
    return 0;
}