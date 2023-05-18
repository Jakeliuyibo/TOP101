class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        arr.resize(n  , vector<int>(m, 0));
        sum.resize(n+1, vector<int>(m+1, 0));
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=0; jj<m; jj++)
            {
                arr[ii][jj]     = matrix[ii][jj];
                sum[ii+1][jj+1] = matrix[ii][jj] + sum[ii+1][jj] + sum[ii][jj+1] - sum[ii][jj];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }


private:
    vector<vector<int>> arr;
    vector<vector<int>> sum;

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */