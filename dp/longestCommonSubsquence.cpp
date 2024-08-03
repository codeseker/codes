Longest Common Subsquence (All approaches are must but Tabulation is most important) 
int solveRec(int ind1, int ind2, string s1, string s2) {
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (s1[ind1] == s2[ind2]) {
        return 1 + solveRec(ind1 - 1, ind2 - 1, s1, s2);
    }

    return max(solveRec(ind1 - 1, ind2, s1, s2),
                solveRec(ind1, ind2 - 1, s1, s2));
}

int solveMem(int ind1, int ind2, string s1, string s2,
                vector<vector<int>>& dp) {
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1) {
        return dp[ind1][ind2];
    }

    if (s1[ind1] == s2[ind2]) {
        return dp[ind1][ind2] =
                    1 + solveMem(ind1 - 1, ind2 - 1, s1, s2, dp);
    }

    return dp[ind1][ind2] = max(solveMem(ind1 - 1, ind2, s1, s2, dp),
                                solveMem(ind1, ind2 - 1, s1, s2, dp));
}

int solveTab(string s1, string s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1]) {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            } else {
                dp[ind1][ind2] =
                    max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    return dp[n][m];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length(), m = text2.length();
    
    return solveTab(text1, text2, n, m);
}