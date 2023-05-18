#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
// #include<bits/stdc++.h>

using namespace std;

int tmp[50]{0};
// int Fibonacci(int n) 
// {
//     if(n==1) return 1;
//     if(n==2) return 1;

//     if(tmp[n] > 0) return tmp[n];
//     else
//     {
//         tmp[n] = Fibonacci(n-1) + Fibonacci(n-2);
//         return tmp[n];
//     }
// }
int Fibonacci(int n) 
{
    int llast = 1;
    int last  = 1;
    int curr  = 1;

    for(int idx=3; idx<=n; idx++)
    {
        llast = last;
        last = curr;
        curr = llast + last;
    }
    return curr;
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