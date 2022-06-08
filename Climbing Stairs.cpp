class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        /*O(n) space DP
        vector<int> dp(n+1,0);
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for(int i = 3; i<=n ; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
        */
        //Constant Space DP:
        int i0 = 0, i1 = 1, i2 = 2, ans;
        for(int i = 3; i<=n; i++)
        {
            ans = i2 + i1;
            i1 = i2;
            i2 = ans;
        }
        return ans;
    }
};
