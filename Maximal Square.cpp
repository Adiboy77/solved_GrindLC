/*
Explanation:dp(i,j) represents the side length of the maximum square whose bottom right corner is the cell with index (i,j) in the original matrix.
Starting from index (0,0), for every 1 found in the original matrix, we update the value of the current element as
dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
We also remember the size of the largest square found so far. In this way, we traverse the original matrix once and find out the required maximum size. This gives the side length of the square (say maxsqlenmaxsqlen). The required result is the area maxsqlen^2maxsqlen 
2
 .
 
DP using O(mn) space: BUT MORE UNDERSTANDABLE SOLUTION:
int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(cols+1,0));
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) 
        {
            for (int j = 1; j <= cols; j++) 
            {
                if (matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
*/

//DP using linear space: BUT GO FOR THE ABOVE SOLUTION AS IT IS MORE UNDERSTANDABLE
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols+1,0);
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; i++) 
        {
            for (int j = 1; j <= cols; j++) 
            {
               int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;//Imp. calculation for getting a square only and not a rectangle
    }
};
