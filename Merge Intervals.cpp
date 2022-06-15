class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        vector<vector<int>> out;
        for(int i=1;i<n;i++)
        {
            if(v[i][0] > v[i-1][1])
            {
                out.push_back(v[i-1]);
            }
            else
            {
                v[i][0] = min(v[i-1][0],v[i][0]);
                v[i][1] = max(v[i-1][1],v[i][1]);
            }
        }
        int ns = out.size();
        if(ns==0 || v[n-1][0] > out[ns-1][1])
        {
            out.push_back(v[n-1]);
            return out;
        }
        return out;
    }
};
