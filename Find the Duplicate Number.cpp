class Solution {
public:
    //Floyd's cycle detection algo in arrays
    //Can also do it without modifying nums, by maintaining 2 pointers for nums[0] and nums[nums[0]]
    int findDuplicate(vector<int>& nums) {
      while (nums[0] != nums[nums[0]])
            swap(nums[0], nums[nums[0]]);
        return nums[0];
    }
};
