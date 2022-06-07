class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0), cmp(26,0);
        int n1 = s.length(), n2 = t.length();
        if(n1!=n2)return false;
        for(int i=0;i<n1;i++)
        {
             freq[s[i]-'a']++;
            cmp[t[i]-'a']++;
        }
           
        for(int i=0;i<26;i++)
            if(freq[i]!=cmp[i])
                return false;
        return true;
    }
};
