/*
Follow up:
For the follow up part where unicode characters are used, we can just increase the size of array to number of characters in unicode and first letter's ASCII code could be adjusted to zero.

Once the map(array) is ready, we can now iterate over the second string and decrease the frequencies of corresponding elements on each iteration.
Then finally, iterate over the map and check if any element is non-zero and return false in this case, otherwise return true.
Like:
//help in easy switch to follow up case
#define CHAR_COUNT 26
#define FIRST_CHAR 97   //ASCII code of first char('a' in this case)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        int freqArray[CHAR_COUNT] = {0};
		
        for(int i = 0; i < s.length(); i++){
            ++freqArray[s[i] - FIRST_CHAR];
            --freqArray[t[i] - FIRST_CHAR];
        }

        for(int i = 0; i < CHAR_COUNT; i++)
            if(freqArray[i]!=0) return false;
        return true;
    }
};

//Or if unicode characters are say > 10^6, then we can simply sort the given strings and compare and return because we cannot create a space for that much of a large array
*/
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
        return freq == cmp ;
    }
};
