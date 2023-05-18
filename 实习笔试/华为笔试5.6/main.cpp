#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1,2,3,1,2,3,6,8,9,1};

    if(lower_bound(arr.begin(), arr.end(), 1) == arr.end())
        cout << 1 << endl;
    else
        cout << 2 << endl;
    
    return 0;
}