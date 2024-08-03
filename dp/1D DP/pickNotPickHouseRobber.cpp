House Robber(picking / notpicking) int solveRec(int index, vector<int> &nums)
{
    if (index < 0)
        return 0;

    int pick = nums[index] + solveRec(index - 2, nums);
    int notPick = solveRec(index - 1, nums);

    return max(pick, notPick);
}

int solveMem(int index, vector<int> &nums, vector<int> &dp)
{
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int pick = nums[index] + solveMem(index - 2, nums, dp);
    int notPick = solveMem(index - 1, nums, dp);

    return dp[index] = max(pick, notPick);
}