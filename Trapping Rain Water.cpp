class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, leftMax = 0, rightMax = 0, fin_ans;
        //So we update l and r, whosoever's height is smaller, & this is done in hope of getting a higher height value at that index after doing l++ or r-- because the amount of water trapped most certainly depends upon that bar (out of leftMax & rightMax) whose height is smaller
        while(l <= r)
        {
            if(height[l] <= height[r])//here may or may not include =
            {
                if(height[l] >= leftMax)
                    leftMax = height[l];
                else
                    fin_ans += (leftMax - height[l]);
                l++;
            }
            else
            {
                if(height[r] >= rightMax)
                    rightMax = height[r];
                else
                    fin_ans += (rightMax - height[r]);
                r--;
            }
        }
        return fin_ans;
    }
};
