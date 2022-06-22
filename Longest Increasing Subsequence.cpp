class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cmp;
        cmp.push_back(nums[0]);
        int ans = 1;
        for(int i = 1 ; i<n ; i++)
        {
            if(nums[i] <= cmp[ans-1])
            {
                int pos = lower_bound(cmp.begin(),cmp.end(),nums[i]) - cmp.begin();
                cmp[pos] = nums[i];
            }
            else
            {
                cmp.push_back(nums[i]);
                ans++;
            }
        }
        return ans;
    }
};
