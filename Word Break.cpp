class Solution {
public:
     /*  We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there. The optimization is to look from current position i back and only substring and do dictionary look up in case the preceding position j with dp[j] == true is found.*/
    
    /*
    One pruning is done that we only take j back up until the length of largest existing word in dictionary which will reduce the time to 0 ms
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int n = wordDict.size(), longestWord = 0;;
        if(n == 0)
            return false;
        for(int i = 0; i < n; i++)
        {
            dict.insert(wordDict[i]);
            int tempSize = wordDict[i].length();
            longestWord = max(longestWord , tempSize);
        }
     
        vector<bool> dp(s.size() + 1, false);
        dp[0]=true;
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = i-1; j >= max(i - longestWord , 0); j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j , i-j);
                    if(dict.find(word) != dict.end())
                    {
                        dp[i]=true;
                        break; //skips to next i
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
