class Solution {
public:
    int coinChange(vector<int>& num, int x) {
          int n = num.size();
    vector<int> prev(x+1,0) , curr(x+1,0);
    for(int t=0;t<=x;t++)
    {
        if(t%num[0] == 0)
            prev[t] = t / num[0];
        else
            prev[t] = 1e9;
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int t=0;t<=x;t++)
        {
            int notTake = 0 + prev[t];
            int take = INT_MAX;
            if(num[ind] <= t)
                take = 1 + curr[t-num[ind]];
            curr[t] = min(notTake,take);
        }
        prev = curr;
    }
    int ans = prev[x];//or curr[x] ; same like in every prev, curr video
    if(ans >= 1e9)
        ans = -1;
	return ans;

    }
};
