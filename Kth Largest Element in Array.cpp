/*
For brute solutions look:https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/893847/C%2B%2B-Ten-Solutions
Brute Solutions:
1.)STL nth_element
int findKthLargest(vector<int>& nums, int k) {
	nth_element(nums.begin(),nums.begin()+nums.size()-k,nums.end());
	return nums[nums.size()-k];
}
int findKthLargest(vector<int>& nums, int k) {
	nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
	return nums[k-1];
}

2.)MaxHeap using priority_queue
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int> pq(nums.begin(),nums.end());
	for(int i=1;i<k;++i) pq.pop();
	return pq.top();
}

3.)MinHeap using priority_queue
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<nums.size();++i){
		pq.push(nums[i]);
		if(pq.size()>k) pq.pop();
	}
	return pq.top();            
}
*/
//Learn more about quick select algorithm
/*
The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the k-th smallest element. The logic is simple, if index of the partitioned element is more than k, then we recur for the left part. If index is the same as k, we have found the k-th smallest element and we return. If index is less than k, then we recur for the right part. This reduces the expected complexity from O(n log n) to O(n), with a worst-case of O(n^2).

Why quick select's time is O(n) and not nlogn?
n log(n) implies that the algorithm looks at all N items log(n) times. But that's not what's happening with Quickselect.

Let's say you're using Quickselect to pick the top 8 items in a list of 128. And by some miracle of random selection, the pivots you pick are always at the halfway point.

On the first iteration, the algorithm looks at all 128 items and partitions into two groups of 64 items each. The next iteration splits into two groups of 32 items each. Then 16, and then 8. The number of items examined is:

N + N/2 + N/4 + N/8 + N/16
The sum of that series will never reach 2*N.


Why quick select's worst case is O(n^2)?
The worst case is that partitioning always results in very skewed partition sizes. Consider what would happen if the first partitioning only removed one item. And the second only removed one, etc. The result would be:

N + (N-1) + (N-2) ...

Which is (n^2 + n)/2), or O(n^2).
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
