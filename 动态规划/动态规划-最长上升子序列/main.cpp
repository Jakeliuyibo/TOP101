#include <iostream>
#include <vector>

using namespace std;


int main() {
    // 输入处理 
    int n;
    cin >> n;
    vector<int > array(n, 0);
    for(int idx=0; idx<n; idx++)
        cin >> array[idx];
    
    int result = 0;
    vector<int> dp(n, 0);
    for(int ii=1; ii<n; ii++)
    {
        for(int jj=0; jj<ii; jj++)
        {
            if(array[ii] > array[jj])
                dp[ii] = max(dp[ii], dp[jj]+1);
        }
        result = max(result, dp[ii]);
    }

    cout << result+1 << endl;

    return 0;
}
// 64 位输出请用 printf("%lld")