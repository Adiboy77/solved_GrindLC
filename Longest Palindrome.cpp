class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> fl(26,0), fu(26,0);
        int n = s.length();
        for(int i= 0; i<n; i++)
        {
            if(isupper(s[i]))
                fu[s[i]-'A']++;
            else
                fl[s[i]-'a']++;
        }
        int ans = 0, flag = 0;
        for(int i = 0; i < 26; i++)
        {
            if((flag == 0) && (fl[i]%2 || fu[i]%2))
            {
                flag = 1;
            }
            fl[i] = ((fl[i]/2)*(2));
            fu[i] = ((fu[i]/2)*(2));
            ans += (fl[i]+fu[i]);
        }
        if(flag)
            ans++;
        return ans;
    }
};
