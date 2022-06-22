class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0, end = n - 1;
        int ans = INT_MIN;
        while(start < end)
        {
            int mine = min(height[start],height[end]);
            int cur = ((mine)*(end - start));
            ans = max(ans,cur);
            if(height[start] <= height[end])
                start++;
            else
                end--;
        }
        return ans;
    }
};
