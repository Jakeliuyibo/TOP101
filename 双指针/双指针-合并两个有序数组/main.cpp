#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
    void merge(int A[], int m, int B[], int n) 
    {
        int idx_a = m-1;
        int idx_b = n-1;

        for(int kk=(m+n-1); kk>=0; kk--)
        {
            // printf("curr kk=%d, idx_a=%d idx_b=%d\n", kk, idx_a, idx_b);
            /* 检测数组A和数组B末位 */
            if(idx_a < 0)
            {
                A[kk] = B[idx_b];
                if(idx_b>=0) idx_b--;
            }
            else if(idx_b < 0)
            {
                A[kk] = A[idx_a];
                if(idx_a>=0) idx_a--;
            }
            else
            {
                if(A[idx_a] < B[idx_b])
                {
                    A[kk] = B[idx_b];
                    if(idx_b>=0) idx_b--;
                }
                else
                {
                    A[kk] = A[idx_a];
                    if(idx_a>=0) idx_a--;
                }
            }
        }
    }
};



int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int a[] = {1,2,3};


    for (auto i:a)
    {
        cout << i << endl;
    }



    return 0;
}