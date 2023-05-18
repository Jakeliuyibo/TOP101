bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Solution {
public:


    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();   // 项目个数

        /* 按最小启动资本排序   */
        vector<vector<int>> arr(n, vector<int>(2,0));
        for(int ii=0; ii<n; ii++)
        {
            arr[ii][0] = profits[ii];
            arr[ii][1] = capital[ii];
        }
        sort(arr.begin(), arr.end(), cmp);

        /* 优先选择利润大的 */
        int num_project = 0;
        priority_queue<int, vector<int>, less<int>> q;

        /* 存入所有满足最小资本的利润*/
        int idx = 0;
        while(num_project<k)
        {
            /* 存入所有满足最小资本的利润*/
            while(idx<n && w >= arr[idx][1])
            {
                q.push(arr[idx][0]);
                idx++;
            }

            /* 取出一个项目投资 */
            if(q.size()==0)
                break;

            w += q.top();
            q.pop();
            num_project++;
        }

        return w;
    }
};