/*
Make an extra copy and then rotate.
Time complexity: O(n). Space complexity: O(n).

    class Solution 
    {
    public:
        void rotate(int nums[], int n, int k) 
        {
            if ((n == 0) || (k <= 0))
            {
                return;
            }
            
            // Make a copy of nums
            vector<int> numsCopy(n);
            for (int i = 0; i < n; i++)
            {
                numsCopy[i] = nums[i];
            }
            
            // Rotate the elements.
            for (int i = 0; i < n; i++)
            {
                nums[(i + k)%n] = numsCopy[i];
            }
        }
    };
    
    Another solution:
    Start from one element and keep rotating until we have rotated n different elements.
Time complexity: O(n). Space complexity: O(1).

    class Solution 
    {
    public:
        void rotate(int nums[], int n, int k) 
        {
            if ((n == 0) || (k <= 0))
            {
                return;
            }
            
            int cntRotated = 0;
            int start = 0;
            int curr = 0;
            int numToBeRotated = nums[0];
            int tmp = 0;
            // Keep rotating the elements until we have rotated n 
            // different elements.
            while (cntRotated < n)
            {
                do
                {
                    tmp = nums[(curr + k)%n];
                    nums[(curr+k)%n] = numToBeRotated;
                    numToBeRotated = tmp;
                    curr = (curr + k)%n;
                    cntRotated++;
                } while (curr != start);
                // Stop rotating the elements when we finish one cycle, 
                // i.e., we return to start.
                
                // Move to next element to start a new cycle.
                start++;
                curr = start;
                numToBeRotated = nums[curr];
            }
        }
    };
*/
//Reverse the first n - k elements, the last k elements, and then all the n elements.
//Time complexity: O(n). Space complexity: O(1).
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         k = k%n;
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            reverse(nums.begin(), nums.begin() + n - k);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
            reverse(nums.begin() + n - k, nums.end());
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            reverse(nums.begin(), nums.end());
    }
};
