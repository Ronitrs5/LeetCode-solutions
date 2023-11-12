class Solution {
public:

    const int mod = 1000000007;

    int sol(int i, int j, int moves, int m, int n, vector<vector<vector<int>>> &dp){

        if((i < 0) || (i >= m) || (j < 0) || (j >= n))
            return 1;

        if(moves == 0)
            return 0;

        if(dp[moves][i][j] != -1) return dp[moves][i][j];

        long long up = sol(i - 1, j, moves - 1,m, n, dp);
        long long down = sol(i + 1, j, moves - 1,m, n, dp);
        long long left = sol(i, j - 1, moves - 1,m, n, dp);
        long long right = sol(i, j + 1, moves - 1,m, n, dp);

        return dp[moves][i][j] = (up+down+left+right) % mod;

    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>> (m + 1, vector<int>(n + 1, -1)));
        return sol(startRow, startColumn, maxMove, m, n, dp);
    }
};
