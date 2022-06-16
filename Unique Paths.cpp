class Solution {
public:
    /*Memoization helper
    int helper(int i,int j,vector< vector<int> > &dp)
    {
        if(i<0 || j<0)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = helper(i-1,j,dp);
        int left = helper(i,j-1,dp);
        return dp[i][j] = up+left;
    }
    */
    /*
    DP:
    int uniquePaths(int m, int n) {
        vector< vector<int> > dp(m+1,vector<int> (n+1,0));
        for(int i = 1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1 && j==1)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
    */
    //Most optimal code:
    int uniquePaths(int m, int n) {
        vector<int> cur(n+1,0), prev(n+1,0);
        for(int i = 1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1 && j==1)
                    cur[j] = 1;
                else
                {
                    cur[j] = prev[j] + cur[j-1];
                }
            }
            prev = cur;
        }
        return prev[n];
    }
};
