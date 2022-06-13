class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int fp = n, fn = n-1;//Initializing fp with n, for handling the case of all negative numbers.
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                fp = i;
                break;
            }
        }
        fn = fp - 1;
        vector<int> out;
        while(fp < n && fn>=0)
        {
            int cmp1 = nums[fp]*nums[fp], cmp2 = nums[fn]*nums[fn];
            if(cmp1 < cmp2)
            {
                out.push_back(cmp1);
                fp++;
            }
            else if(cmp1 > cmp2)
            {
                out.push_back(cmp2);
                fn--;
            }
            else
            {
                out.push_back(cmp1);
                out.push_back(cmp2);
                fn--;
                fp++;
            }
        }
        while(fn >= 0)
        {
            out.push_back(nums[fn]*nums[fn]);
            fn--;
        }
        while(fp < n)
        {
            out.push_back(nums[fp]*nums[fp]);
            fp++;
        }
        return out;
    }
};
