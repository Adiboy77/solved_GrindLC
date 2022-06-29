//Maximum non adjacent sum code
/*
DP code:
int maximumNonAdjacentSum(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    int dp[n];
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        int pick = INT_MIN;
        if(i>1)
        pick = arr[i]+dp[i-2];
        else
        pick = arr[i];//was missing this condition, ie if i==1
        
        int nonPick = dp[i-1];
        dp[i]=max(pick,nonPick);
    }
    return dp[n-1];
}
*/
class Solution {
public:
    int rob(vector<int>& arr) {
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int pick = INT_MIN;
        if(i>1)
        pick = arr[i]+prev2;
        else
        pick = arr[i];//was missing this else condition, ie if i==1
        
        int nonPick = prev;
        int curr = max(pick,nonPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
    }
};
