// **题目描述：**实现一个程序 search_matrix(matrix), 参数 matrix 是一个仅包含 0 或 1 两种数字的矩阵,
// 程序应返回输入矩阵中包含的最大正方形子矩阵(长和宽相等)的区域面积。
// 例如 : 如果 matrix 是[“1010111111”, “000000011”, “1010110111”, “0000110001”, 那么它看起来像下面的阵:
// 1010111111
// 0000000111
// 1010110111
// 0000110001
// 对于上面的输入, 最大的子矩阵是一个 3x3 的矩阵, 程序只要返回最大子矩阵的面积即可, 如上面的矩阵即返回 9(3x3)。
// 输入描述 : 第 1 行输入为一个数字 N, 代表下面有几行
// 第 2 行到第 N + 1 行是代表矩阵的 0 和 1 组成的字符串, 每行的长度相同
// 输出描述 :
// 返回一个数字, 代表输入矩阵的最大正方子矩阵的面积。
// 示例 1
// 输入
// 3
// 110
// 111
// 110
// 输出
// 4
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int maxlen(vector<vector<char>>matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
	int len = 0;
	vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
	for (int i = 0; i < matrix.size(); i++) 
    {
		for (int j = 0; j < matrix[0].size(); j++) 
        {
			if (matrix[i][j] == '1') 
            {
				if(i==0 || j==0) 
                {
					dp[i][j] = 1;
				}
				else 
                {
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				}
			}
			len = max(len, dp[i][j]);
		}
	}
	return len * len;
}

int main() {
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    int lens = 0;
    cin >> lens;
    
    vector<vector<char>> matrix;
    for(int idx=0; idx<lens; idx++)
    {
        string input_str;
        cin >> input_str;
        vector<char> char_vec;

        for(int jj=0; jj<input_str.size(); jj++)
        {
            char_vec.push_back(input_str[jj]);
        }

        matrix.push_back(char_vec);
    }

    /* 求   */
    int ret = 0;
    ret = maxlen(matrix);
    cout << ret;

	return 0;
}
