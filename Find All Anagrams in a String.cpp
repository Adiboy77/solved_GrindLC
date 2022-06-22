class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sn = s.length();
        int pn = p.length();
        vector<int> out;
        if(pn>sn)
            return out;
        else
        {
            vector<int> freq(26,0);
            vector<int> res(26,0);//stores the freq of smaller string p, never changed, just for comparison as we can't use substr function because of anagrams can be rearranged also.
            for(int i=0;i<pn;i++)
                res[p[i]-'a']++;
            for(int i=0;i<pn;i++)//pn is the window size
              freq[s[i]-'a']++;
            if(freq == res)//for first window
                out.push_back(0);
            int start = 0;
            for(int i=pn;i<sn;i++)//i acts as end, and pn acts as window size.
            {
                freq[s[i]-'a']++;
                freq[s[start]-'a']--;
                start++;
                if(freq == res)
                    out.push_back(start);
            }
        }
            return out;
    }
};
