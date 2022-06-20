class Solution {
public:
    void helper(int open,int close,int n,string current, vector<string> &result)
    {
        if(current.length()==n*2)
        {
            result.push_back(current);
            return ;
        }
        if(open<n)  helper(open+1,close,n,current+"(",result);
        if(close<open)  helper(open,close+1,n,current+")",result);
    }
    vector<string> generateParenthesis(int n) {
         vector<string>result;
        helper(0,0,n,"",result);
        return result;
    }
};
