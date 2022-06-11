class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        int minL = 201;
        for(int i = 0;i<n;i++)
        {
            int temp = strs[i].length();
            minL = min(minL,temp);
        }
        for(int j=0;j<minL;j++)
        {
            int flag = 0;
            char cmp = strs[0][j];
           
            for(int i = 1;i<n;i++)
            {
                if(strs[i][j] != strs[i-1][j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
            else
                ans+=cmp;
        }
        return ans;
    }
};
