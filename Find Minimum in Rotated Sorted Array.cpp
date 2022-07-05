//Binary Search
class Solution {
public:
    /*
    Prev solution using Errichto's channel:
      int findMin(vector<int>& nums) {
         int n = nums.size(),left = 0,right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[left]>nums[right])
                if(nums[left]>nums[mid])
                    right = mid;
                else
                    left = mid+1;
            else
                return nums[left];
        }
        return nums[0];
    }
    */
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return nums[lo];
    }
   
};
