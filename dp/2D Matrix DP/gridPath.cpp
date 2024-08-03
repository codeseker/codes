Grid Path(this is when we have to count all possible paths / ways we add out recursive solution)

    int solveMem(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = 0;
    if (col > 0)
    {
        left = solveMem(row, col - 1, dp);
    }
    int top = 0;
    if (row > 0)
    {
        top = solveMem(row - 1, col, dp);
    }
    return dp[row][col] = top + left;
}