#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

/**
 * 
 * @param m int整型 
 * @param n int整型 
 * @return int整型
 */
int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    /* 初始化第0列    */
    for(int ii=0; ii<m; ii++)
        dp[ii][0] = 1;

    /* 初始化第0行      */
    for(int jj=0; jj<n; jj++)
        dp[0][jj] = 1;
    
    for(int ii=1; ii<m; ii++)
    {
        for(int jj=1; jj<n; jj++)
        {
            dp[ii][jj] = dp[ii][jj-1] + dp[ii-1][jj];
        }
    }

    return dp[m-1][n-1];
    // write code here
}


// int uniquePaths(int m, int n) 
// {
//     if(m==1 || n==1) return 1;

//     return uniquePaths(m-1,n) + uniquePaths(m,n-1);
// }


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