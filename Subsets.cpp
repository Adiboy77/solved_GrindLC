class Solution {
public:
    /*Using [1, 2, 3] as an example, the iterative process is like:
Initially, one empty subset [[]]
Adding 1 to []: [[], [1]];
Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2,3]].
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> out;
        out.push_back({});
        for(int i = 0;i<n;i++)
        {
            int ns = out.size();
            for(int j = 0;j<ns;j++)
            {
                out.push_back(out[j]);
                out.back().push_back(nums[i]);
            }
        }
        return out;
    }
};
