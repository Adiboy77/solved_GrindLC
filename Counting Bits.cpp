class Solution {
public:
    //Very Important DP observation, dry run the code if not understanding
    vector<int> countBits(int n) {
        vector<int> out(n+1);
        out[0] = 0;
        for(int i = 1;i<=n;i++)
        {
            if(i%2)
                out[i] = out[i-1] + 1;//just 1 gets added on to the LSB of the even number i-1.
            else
                out[i] = out[i/2];//for even i, all one bits just left shift by 1 place in i/2
        }
        return out;
    }
};
