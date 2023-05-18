#include <bits/stdc++.h>

using namespace std;

int MAX_SIZE = 20;

int main()
{
    freopen("in.txt", "r", stdin);
    /* 输入处理 */
    int M;
    cin >> M;
    int nums;
    cin >> nums;
    int axis[MAX_SIZE][MAX_SIZE][nums];
    int range[nums][4];
    memset(range, 0, sizeof(range));
    memset(axis, 0, sizeof(axis));
    for(int ii=0; ii<nums; ii++)
    {
        int cur_x, cur_y = 0;
        cin >> cur_x >> cur_y;
        axis[cur_x][cur_y][ii] = 1;
        range[ii][0] = cur_x;
        range[ii][1] = cur_y;
        range[ii][2] = cur_x;
        range[ii][3] = cur_y;
    } 

    /* */
    for(int days=1; days<100; days++)
    {
        /* 更新范围 */
        for(int ii=0; ii<nums; ii++)
        {
            range[ii][0] = max(0, range[ii][0]-1);
            range[ii][1] = max(0, range[ii][1]-1);
            range[ii][2] = min(MAX_SIZE, range[ii][2]+1);
            range[ii][3] = min(MAX_SIZE, range[ii][3]+1);
        }

        /* 更新地图 */
        for(int ii=0; ii<nums; ii++)
        {
            for(int x=range[ii][0]; x<=range[ii][2]; x++)
            {
                for(int y=range[ii][1]; y<=range[ii][3]; y++)
                {
                    axis[x][y][ii] = days+1;
                }
            }
        }

        printf("第%d天\n", days);
        for(int ii=0; ii<nums; ii++)
        {
            printf("物种%d\n", ii);
            for(int x=0; x<MAX_SIZE; x++)
            {
                for(int y=0; y<MAX_SIZE; y++)
                {
                    printf("%d ", axis[x][y][ii]);
                }
                printf("\n");
            }
            printf("\n");
        }

        /* 找到相交点       */
        for(int x=0; x<MAX_SIZE; x++)
        {
            for(int y=0; y<MAX_SIZE; y++)
            {
                int sum = 0;
                for(int ii=0; ii<nums; ii++)
                {
                    if(axis[x][y][ii] > 0)
                    {
                        sum++;
                    }
                }
                if(sum >= M)
                {
                    cout << days << endl;
                    return 0;
                }
            }
        }
    }


    /* 输出处理     */


    return 0;
}