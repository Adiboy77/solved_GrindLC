class Solution {
public:
    bool canJump(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    for (int reach = 0; i < n && i <= reach; ++i)//very important && i<=reach condition because it makes sure that for any particular 'i',  we cannot jump to a more higher value than nums[i] and if we do, ew break the loop.
        reach = max(i + nums[i], reach);
    return i == n;
    }
};
