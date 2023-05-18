struct PPP
{
    int num;
    int time;
};
bool operator < (PPP cp1, PPP cp2)
{
    return cp1.time < cp2.time;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> mp;
        for(auto n:nums)
            mp[n]++;


        priority_queue<PPP, vector<PPP>, less<PPP>> q;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            PPP cur = {it->first, it->second};
            q.push(cur);
        }

        vector<int> res;
        for(int ii=0; ii<k; ii++)
        {
            res.push_back(q.top().num);
            q.pop();
        }
        return res;
    }
};