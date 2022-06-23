/*
For brute solutions look:https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/893847/C%2B%2B-Ten-Solutions
*/
//Learn more about quick select algorithm
/*
The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the k-th smallest element. The logic is simple, if index of the partitioned element is more than k, then we recur for the left part. If index is the same as k, we have found the k-th smallest element and we return. If index is less than k, then we recur for the right part. This reduces the expected complexity from O(n log n) to O(n), with a worst-case of O(n^2).
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	//partition rule: >=pivot   pivot   <=pivot
	int left=0,right=nums.size()-1,idx=0;
	while(1){
		idx = partition(nums,left,right);
		if(idx==k-1) break;
		else if(idx < k-1) left=idx+1;
		else right= idx-1;
	}
	return nums[idx];
}
int partition(vector<int>& nums,int left,int right){//hoare partition
	int pivot = nums[left], l=left+1, r = right;
	while(l<=r){
		if(nums[l]<pivot && nums[r]>pivot) swap(nums[l++],nums[r--]);
		if(nums[l]>=pivot) ++l;
		if(nums[r]<=pivot) --r;
	}
	swap(nums[left], nums[r]);
	return r;
}
};
