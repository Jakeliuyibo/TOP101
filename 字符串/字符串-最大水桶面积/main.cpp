#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param height int整型vector 
 * @return int整型
 */
int maxArea(vector<int>& height) 
{
    if(height.size() < 2)
    {
        return 0;
    }
    
    int max_size = 0;

    int ii=0;
    int jj=height.size()-1;
    while(ii < jj)
    {
        int curr_size =(jj-ii) * min(height[ii], height[jj]); 
        if(curr_size > max_size)
        {
            max_size = curr_size;
        }

        if(height[ii] < height[jj])
        {
            ii++;
        }
        else
        {
            jj--;
        }

    }
    return max_size;
}



int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> input = {1,7,3,2,4,5,8,2,7};
    cout << maxArea(input) << endl;

    return 0;
}