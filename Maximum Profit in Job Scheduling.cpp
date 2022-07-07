/*DP solution:
 int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size(),i=0,ans=0;
        vector< pair<int,int> >v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({startTime[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> dp(n,0);
        
        for(i=n-1;i>=0;i--)
        {
            int f= v[i].first;
            int ii=v[i].second;
            int val=0;
            
            val+=profit[ii];
            
            int x= endTime[ii];
            
            auto it= lower_bound(v.begin(),v.end(),x,[](const pair<int,int> &p, const int &value){
                return p.first<value;
            });       //searching for next Starttime which is greater than the current endtime
            
            if(it!=v.end())
            {
                int j=it-v.begin();
                
                val+=dp[j];
            }
            
            if(i==n-1)
            dp[i]=max(dp[i],val);
            
            else
            {
                dp[i]=max(dp[i],max(val, dp[i+1]));//either take the ith job or skip it and take the next one
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
*/
class Job{
    public:
    int start;
    int end;
    int profit;
};
bool compare(Job a,Job b)
{
    if(a.end==b.end)
    {
        return a.start<b.start;
    }
    return a.end<b.end;
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       //map will store max profit till ith job endTime
        map<int,int>m;
        int n=startTime.size();
        vector<Job>temp(n);
        
        for(int i=0;i<n;i++)
        {
            Job p;
            p.start = startTime[i];
            p.end = endTime[i];
            p.profit = profit[i];
            temp[i]=p;
        }
        int ans=0;
        sort(temp.begin(),temp.end(),compare);
        
        for(int i=0;i<n;i++)
        {
            //max profit of previous job  with same endTime as ith job
            int u=m[temp[i].end]; 
            
            m[temp[i].end]=temp[i].profit;
            
            // try to find previous job whose endtime is less than or equal to 
            //current job startTime
            int j=i-1;
            while((j>=0)&&temp[i].start<temp[j].end)
            {
                 j--;
            }
            //j<0 if no previous job endtime is less or equal to current job startTime
            if(j>=0)
            {
                m[temp[i].end]+=m[temp[j].end];
            }
            //profit only with ith job
            ans=max(m[temp[i].end],ans);
            
            //----------------------//
            // previous job endTime is same as current ith job endtime
            //then will compare earlier profit with current profit 
            ans=max(ans,u); 
            
            
            m[temp[i].end]=ans; //max profit till ith job
            
        }
        return ans;
        
    }
};
