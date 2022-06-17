class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ns = tasks.size();
        vector<int> freq(26,0);
        for(int i=0;i<ns;i++)
            freq[tasks[i]-'A']++;
        int maxf = *max_element(freq.begin(),freq.end());
        //maxf = max(maxf,ns-maxf);
        int ans = ((maxf-1)*(n+1));//+1 here is handled in next loop as automatically 1 element would be = maxf
        for(int i=0;i<26;i++)
            if(freq[i] == maxf)
                ans++;
        return max(ns,ans);
    }
};
