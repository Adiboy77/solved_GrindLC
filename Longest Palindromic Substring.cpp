//Time: O(n^2)
//Space: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool table[n][n];
        
        // to initialize table with value 0
        memset(table,0,sizeof(table));
        
        int maxLength=0;//stores the maximum length of the longest palindromic substring
        int start = 0;//stores the starting index of the longest pallindromic substring
        
        // for all substring of size 1
        for(int i=0;i<n;i++){
            table[i][i]=1;
            start=0;
            maxLength=1;
        }
        
        // for all substring of size 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                table[i][i+1]=1;
                start=i;
                maxLength=2;
            }
        }
        
        // for all substring of size 3->n
        //Pay attention to how both the loops iterate the subtrings of 's'
        for(int k=2;k<n;k++){
            int beg=0;
            int end=k;
            for(;end<n;beg++,end++){
                if(s[beg]==s[end] && table[beg+1][end-1]){//means S(i,j) is a palindrome if S(i+1,j-1) is a palindrome and S[i] == S[j]
                    table[beg][end]=1;
                    if((k+1)>maxLength){
                        maxLength=k+1;
                        start=beg;
                    }
                }
            }
        }
        return s.substr(start,maxLength);
    }
};
