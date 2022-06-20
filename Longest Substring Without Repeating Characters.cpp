//2 pointers question, for storing frequencies, we should use hashmap here and not the freq array because s can contain letters, digits, symbols, and spaces as well
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1)
            return n;
        int start = 0, end = 0, ans = 1;
        unordered_map<char,int> m;
        while(end < n)
        {
            m[s[end]]++;
            if(m[s[end]] == 1)
            {
                ans = max(ans , end - start + 1);
            }
            else
            {
                while(m[s[end]] > 1)// when count is greater than 1 then it is repeating
                {
                    m[s[start]]--;//does key gets vanished when a value hits 0 in a map ?
                    start++;// we will compress the window from start, till there is a repeating character
                }
            }
            end++;
        }
        return ans;
    }
};
