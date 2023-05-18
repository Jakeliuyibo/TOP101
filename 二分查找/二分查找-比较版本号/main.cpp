#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> parse_string(string str)
{
    vector<int> vec;
    int tmp = 0;
    for(int idx=0; idx<str.size(); idx++)
    {
        if(str[idx] != '.')
        {
            tmp = 10*tmp + str[idx] - '0';
        }
        else
        {
            vec.push_back(tmp);
            tmp = 0;
        }
        // printf("cuur idx=%d char=%c tmp=%d\n", idx, str[idx], tmp);
    }
    vec.push_back(tmp);
    return vec;
}


int compare(string version1, string version2) 
{
    vector<int> vec1 = parse_string(version1);
    vector<int> vec2 = parse_string(version2);

    /* 暴力比较v1和v2   */
    int record_v1_size = vec1.size();
    int record_v2_size = vec2.size();
    for(int idx=0; idx<max(record_v1_size, record_v2_size); idx++)
    {
        if(vec1[idx] > vec2[idx])
        {
            return 1;
        }
        else if(vec1[idx] < vec2[idx]) 
        {
            return -1;
        }

        /* 补0  */
        if(idx==vec1.size()-1)
        {
            vec1.push_back(0);
        }
        if(idx==vec2.size()-1)
        {
            vec2.push_back(0);
        }
        printf("cuur idx=%d vec1=%d vec2=%d\n", idx, vec1[idx], vec2[idx]);
    }

    return 0;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    string version1;
    string version2;
    cin >> version1;
    cin >> version2;
    cout << compare(version1, version2) << endl;
    return 0;
}