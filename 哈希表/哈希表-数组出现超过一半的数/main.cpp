#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
    int len = numbers.size();

    unordered_map<int, int> mp;
    for(auto idx:numbers)
    {
        mp[idx]++;
        if(mp[idx] > (len/2))
        {
            return idx;
        }
    }
    return 0;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> numbers = {1,2,3,2,2,2,5,4,2};
    int ret = MoreThanHalfNum_Solution(numbers);
    cout << ret << endl;
    return 0;
}
