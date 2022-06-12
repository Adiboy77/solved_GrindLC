class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int finSum = (n*(n+1))/2;
        int cmp = accumulate(nums.begin(),nums.end(),0);
        return finSum-cmp;
    }
};
