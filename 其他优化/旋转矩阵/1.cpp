class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        /* 反转主对角线     */
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=ii+1; jj<n; jj++)
            {
                swap(matrix[ii][jj], matrix[jj][ii]);
            }
        }

        /* 反转左右两半边   */
        for(int ii=0; ii<n; ii++)
        {
            for(int jj=0; jj<n/2; jj++)
            {
                swap(matrix[ii][jj], matrix[ii][n-jj-1]);
            }
        }  
    }
};