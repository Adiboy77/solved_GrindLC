//Time: O(n^2), Space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//I am going to use 2 pointer for that i'm sorting it
        int n=nums.size();
        int sum=nums[0]+nums[1]+nums[2];//Our Intial sum, will keep updating it as minimum and finally return it
        for(int i=0;i<n-2;i++){ 
            //Implementing Two pointer technique
            int j=i+1;
            int k=n-1;
            while(j<k){
                int temp=nums[i]+nums[j]+nums[k];//Temparory sum for comparison
                if(abs(temp-target) < abs(sum-target) ) 
                    sum=temp;//if we find better or closer sum then we update the above sum value
                if(temp>target)
                    k--;                  // if value is greater than target one just come one point right to left
                else if(temp<target)
                    j++;             //if value is lower than target just come one point left to right 
                else 
                    return target;// if value already found no need to go for other just return 
            }
        }
        return sum;
    }
};
