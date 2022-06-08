class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        int nm = magazine.length(), nr = ransomNote.length();
        for(int i = 0; i < nm; i++)
            freq[magazine[i] - 'a']++;
         for(int i = 0; i < nr; i++)
            freq[ransomNote[i] - 'a']--;
        for(int i = 0 ; i<26;i++)
        {
            if(freq[i] < 0)
                return false;
        }
        return true;
    }
};
