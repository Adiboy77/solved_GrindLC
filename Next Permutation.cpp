/*
Why do we reverse here:
1,2,4,5,3,4,3,2,1
iski next perm: 1,2,4,5,3,1,2,3,4

ye isliye because jo first while loop hai that will break at 4(index 5(0based)).
So fir jo ye subsegment hai 4,3,2,1 last ka , ye hmne decreasing order me find kra hai through first while loop, so next permutation of any decreasing order = reverse of that order only(ex.3,2,1 ->nextperm= 1,2,3)

isiliye reverse krrhe

This is the working principle of the whole code basically :
so next permutation of any decreasing order = reverse of that order only(ex.3,2,1 ->nextperm= 1,2,3)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
