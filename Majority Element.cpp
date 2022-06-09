class Solution {
public:
    //Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), count = 0, ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(count == 0)// so by disregarding this prefix, we are ignoring an equal number of majority and minority elements - therefore, say 'x' will still be the majority element in the suffix formed by throwing away the first prefix.
                ans = nums[i];
            if(nums[i] == ans)
                count++;
            else
                count--;
        }
        return ans;
    }
};
