Maximum Path Sum(this is when we have to find a path thas maximum sum in a grid from top to bottom)

    int solveMem(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return grid[0][0];

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = INT_MAX;
    if (col > 0)
    {
        left = grid[row][col] + solveMem(grid, row, col - 1, dp);
    }

    int top = INT_MAX;
    if (row > 0)
    {
        top = grid[row][col] + solveMem(grid, row - 1, col, dp);
    }

    return dp[row][col] = min(left, top);
}