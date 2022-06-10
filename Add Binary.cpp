class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int na = a.length(), nb = b.length();
        int i = na - 1, j = nb - 1;
        char carry = '0';
        while(i>=0 && j>=0)
        {
            if(carry == '0')
            {
                
                if(a[i] == '0' && b[j] == '0')
                    ans+=('0');
                else if(a[i] == '1' && b[j] == '1')
                {
                   ans+=('0');
                    carry = '1';
                }
                else
                   ans+=('1');
            }
            else
            {
                if(a[i] == '0' && b[j] == '0')
                {
                    ans+=('1');
                    carry = '0';
                }
                else if(a[i] == '1' && b[j] == '1')
                   ans+=('1');
                else
                   ans+=('0');
            }
            i--;
            j--;
        }
        while(i>=0)
        {
            if(carry == '0')
               ans+=(a[i]);
            else
            {
                if(a[i] == '0')
                {
                  ans+=('1');
                    carry = '0';
                }
                else
                    ans+=('0');
            }
            i--;
        }
         while(j>=0)
        {
            if(carry == '0')
                ans+=(b[j]);
            else
            {
                if(b[j] == '0')
                {
                    ans+=('1');
                    carry = '0';
                }
                else
                   ans+=('0');
            }
            j--;
        }
        if(carry == '1')
           ans+=('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
