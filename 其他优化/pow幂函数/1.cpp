class Solution {
public:
    double myPow(double x, int n) 
    {
        /* 输入处理     */
        long long N = n;
        if(n < 0)
        {
            N = -N;
        }

        /* logN运算     */
        double res = 1.0;
        while(N)            // 二进制遍历   
        {
            if(N & 0x1)
            {
                res = res * x;
            }
            x = x * x;
            N = N >> 1;
        }

        /* 处理结果 */
        return n > 0 ? res : 1 / res;
    }
};