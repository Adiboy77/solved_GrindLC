class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0,nn=n;
      
        vector<int> v(32,0);
        int pos = 31;
        while(nn)
        {
            v[pos] = (nn%2);
            pos--;
            nn/=2;
        }
        reverse(v.begin(),v.end());
        int ns = v.size();
        for(int i=0;i<ns;i++)
        {
            if(v[i] == 1)
                ans+=((uint32_t)pow(2,ns-1-i));
        }
        return ans;
    }
};
