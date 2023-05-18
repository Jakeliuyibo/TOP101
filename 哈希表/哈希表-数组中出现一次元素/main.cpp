#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// int FindNumsAppearOnce(vector<int> numbers) 
// {
//     int len = numbers.size();

//     unordered_map<int, int> mp;
//     for(auto idx:numbers)
//     {
//         mp[idx]++;
//         if(mp[idx] > (len/2))
//         {
//             return idx;
//         }
//     }
//     return 0;
// }

vector<int> FindNumsAppearOnce(vector<int>& array)
{
    unordered_map<int, int> mp;
    vector<int> ret;

    for(auto num:array)
    {
        mp[num]++;
    }

    for(auto m:mp)
    {
        if(m.second == 1)
        {
            ret.push_back(m.first);
        }
    }

    sort(ret.begin(), ret.end());

    return ret;
}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> numbers = {1,4,1,6};
    vector<int> ret = FindNumsAppearOnce(numbers);
    for(auto idx:ret)
    {
        cout << "idx=" << idx << endl;
    }


    return 0;
}
