#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int> >& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));

    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<m; jj++)
        {
            if(ii==0 && jj==0)  dp[ii][jj] = matrix[ii][jj];
            else if(ii==0)      dp[ii][jj] = matrix[ii][jj] + dp[ii][jj-1];
            else if(jj==0)      dp[ii][jj] = matrix[ii][jj] + dp[ii-1][jj];
            else                dp[ii][jj] = matrix[ii][jj] + min(dp[ii][jj-1], dp[ii-1][jj]);
            // printf("curr ii=%d jj=%d, matrix=%d dp=%d\n", ii, jj, matrix[ii][jj], dp[ii][jj]);
        }
    }

    return dp[n-1][m-1];

}

int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    vector<int> tmp(40){0,1,2,3};


    for(auto t:tmp)
    {
        cout << t << endl;
    }

    return 0;
}