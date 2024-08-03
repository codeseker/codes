Climbing Stair(when we move 1 step or 2 step)

    int climbStairs(int n)
{
    // base casse
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
}
Memo Code : int climbStairs(int n, vector<int> &dp)
{
    // base casse
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
}