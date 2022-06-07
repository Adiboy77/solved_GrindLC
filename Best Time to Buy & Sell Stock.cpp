class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        int minSoFar = prices[0];
        for(int i = 1; i<n; i++)
        {
            minSoFar = min(minSoFar,prices[i]);
            ans = max(ans,prices[i]-minSoFar);
        }
        return ans;
    }
};
