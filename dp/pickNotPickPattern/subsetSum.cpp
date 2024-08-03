Subset Sum(where we have to find if any set of arrays matches to target)

    bool solveRec(int index, int sum, vector<int> &arr)
{

    if (sum == 0)
        return true;
    if (index == 0)
    {
        if (sum == 0)
            return true;
        return false;
    }
    bool pick = false;
    if (arr[index] <= sum)
    {
        pick = solveRec(index - 1, sum - arr[index], arr);
    }
    bool notPick = solveRec(index - 1, sum, arr);

    return pick || notPick;
}

bool solveMem(int index, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (index == 0)
    {
        if (sum == arr[0])
            return true;
        return false;
    }
    if (dp[index][sum] != -1)
        return dp[index][sum];
    bool pick = false;
    if (arr[index] <= sum)
    {
        pick = solveMem(index - 1, sum - arr[index], arr, dp);
    }
    bool notPick = solveMem(index - 1, sum, arr, dp);

    return dp[index][sum] = pick || notPick;
}