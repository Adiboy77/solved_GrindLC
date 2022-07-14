/*
Brute force solution : Using recursion
void bt(vector<int> nums,int target,int total,int &count)
    {
        if(target==total)
        {   count++;
            return;
        }
        
        if(total>target)
            return;
        
        for(int i:nums)
        {
            bt(nums,target,total+i,count);
        }
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        
        int count=0;
        bt(nums,target,0,count);
        
        return count;
        
    }
Memoizing the recursion: DP- Top down approach
int bt(vector<int> nums,int target,vector<int>&cache) 
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(cache[target]!=-1)
            return cache[target];
        int res=0;
        for(int i:nums)
        {
            res+=bt(nums,target-i,cache);
        }
        return cache[target]=res;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> cache(target+1,-1);
        
        return bt(nums,target,cache);
        
    }
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
         //DP - Bottom Up Approach
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j:nums)
            {
                if(i>=j)
                    dp[i]+=dp[i-j];
            }
        }
        
        return dp[target];
    }
};
