class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,0) , curr(k+1,0);
    prev[0] = curr[0] = true;
        if(arr[0]<=k)
    prev[arr[0]] = true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind]<=target)
                take = prev[target-arr[ind]];
            curr[target] = (take || notTake);
        }
        prev = curr;
    }
    return prev[k];
}
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    if(sum%2 != 0)
        return false;
    else
        return subsetSumToK(n,sum/2,arr);
    }
};
