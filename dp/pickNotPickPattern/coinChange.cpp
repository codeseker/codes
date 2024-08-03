Coin chnage problem(where we have to reduce some amount) int solveRec(vector<int> &coins, int target)
{
    // base case
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveRec(coins, target - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}
int solveMem(vector<int> &coins, int target, vector<int> &dp)
{
    // base case
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;
    if (dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveMem(coins, target - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[target] = mini;
    return dp[target];
}
