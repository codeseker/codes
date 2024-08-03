Frog Jump with K ditance(this is when We will use current value as answer) int solve(vector<int> &height, int n, int k, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
        return dp[n];
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int left;
        if (n - i >= 0)
        {
            left = solve(height, n - k, k, dp) + abs(height[n] - height[n - i]);
            mini = min(left, mini);
        }
    }
    return dp[n] = mini;
}
int minimizeCost(vector<int> &height, int n, int k)
{
    // Code here
    vector<int> dp(n + 1, -1);

    return solve(height, n, k, dp);
}