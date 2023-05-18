#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * 
 * @param numbers int整型vector 
 * @param target int整型 
 * @return int整型vector
 */
vector<int> twoSum(vector<int>& numbers, int target) 
{
    vector<int> ret;
    int len = numbers.size();

    // 定义哈希表，unordered_map是用哈希表实现的，复杂度为O(1)，而map是用红黑树实现的
    unordered_map<int, int> hashmap;

	for (int idx=0; idx<len; idx++ )
	{
        if(hashmap.find(target - numbers[idx]) != hashmap.end())
        {
            ret.push_back(hashmap[target - numbers[idx]]+1);
            ret.push_back(idx+1);
            return ret;
        }
        else
        {
            hashmap[numbers[idx]] = idx;
        }
	}
    return ret;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> numbers = {3,2,4};
    int traget          = 6;

    vector<int> ret = twoSum(numbers, traget);
    for(int jj=0; jj<ret.size(); jj++)
    {
        cout << jj << " " << ret[jj] << endl;
    }

    return 0;
}
