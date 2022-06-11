class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //lastNonZeroFoundAt points at the current first 0 of the array, while cur points to the non-zero element to be swapped with that current first 0 which is at lastNonZeroFoundAt.
         for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);//lastNonZeroFoundAt always points to 0's as it is incremented whenever we encounter a non-zero value.
        }
    }
    }
};
//A simple realization is if the current element is non-0, its' correct position can at best be it's current position or a position earlier. If it's the latter one, the current position will be eventually occupied by a non-0 ,or a 0, which lies at a index greater than 'cur' index. 
//All elements before the slow pointer (lastNonZeroFoundAt) are non-zeroes.
//All elements between the current and lastNonZeroFoundAt pointer are zeroes.
