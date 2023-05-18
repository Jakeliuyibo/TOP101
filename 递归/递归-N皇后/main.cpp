#include <iostream>
using namespace std;

int result = 0;

/* 验证是否可放置   */
bool checkValid(vector<vector<int>>& matrix, int x, int y)
{
    /* 验证行   */
    /* 验证列   */
    for(int row=0; row<matrix.size(); row++)
    {
        if(matrix[row][y] == 1) return false;
    }

    /* 验证45度角       */
    for(int ii=x-1, jj=y-1; ii>=0&&jj>=0; ii--,jj--)
    {
        if(matrix[ii][jj] == 1) return false;
    }

    /* 验证135度角      */
    for(int ii=x-1, jj=y+1; ii>=0&&jj<matrix.size(); ii--,jj++)
    {
        if(matrix[ii][jj] == 1) return false;
    }

    return true;
}

/* 递归回溯 */
void helper(vector<vector<int>>& matrix, int row)
{
    /* 终止条件 */
    if(row == matrix.size())
    {
        result++;
        return;
    }

    for(int col=0; col<matrix[0].size(); col++)
    {
        if(checkValid(matrix, row, col))
        {
            /* 递归 */
            matrix[row][col] = 1;
            helper(matrix, row+1);

            /* 回溯 */
            matrix[row][col] = 0;
        }

    }
}


int Nqueen(int n) 
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    helper(matrix, 0);

    return result;
}


int main() 
{
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);

    // ListNode* node5 = new ListNode(5);
    // ListNode* node4 = new ListNode(4);
    // ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(5);
    ListNode* node1 = new ListNode(3);
    node1->next = node2;
    node2->next = nullptr;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = nullptr;

    cout << reverseBetween(node1, 1, 2) << endl;

    return 0;
}
