class Solution {
public:
    //Hashset implies using unordered set, hashmap->unordered map.
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> s;
        for(int i = 0; i<n; i++)
            s.insert(nums[i]);
        for(int i = 0;i<n;i++)
        {
            if(s.find(nums[i]-1) == s.end())//It means we only start counting for consecutiveness of any sequence of the array "from the minimum element of the sequence"
            {
                int cur = 1, ce = nums[i];
                while(s.find(ce + 1) != s.end())
                {
                    cur++;
                    ce++;
                }
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};
