class Solution {
public:
    bool check(char c)
    {
        int k = c;
        if((k>=48 && k<=57) || (k>=65 && k<=90) || (k>=97 && k<=122))
            return true;
        else 
            return false;           
    }
    bool isPalindrome(string s) {
        int n = s.length(), start = 0, end = n - 1;
        while(start < end)
        {
            if(!check(s[start]))
                start++;
            else if(!check(s[end]))
                end--;
            else if(tolower(s[start]) == tolower(s[end]))
            {
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
};
