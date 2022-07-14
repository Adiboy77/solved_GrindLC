class Solution {
public:
    /*
    Another stack solution but O(n) space:

public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());//peek is .top()
                }
            }
        }
        return maxans;
    }
    */
    /*
    Algorithm: Time:O(n), Space:O(1)

In this approach, we make use of two counters leftleft and rightright. First, we start traversing the string from the left towards the right and for every \text{‘(’}‘(’ encountered, we increment the leftleft counter and for every \text{‘)’}‘)’ encountered, we increment the rightright counter. Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string and keep track of maximum length substring found so far. If rightright becomes greater than leftleft we reset leftleft and rightright to 00.

Next, we start traversing the string from right to left and similar procedure is applied.
    */
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == '(') 
                left++;
            else 
                right++;
            
            if (left == right) 
                maxlength = max(maxlength, 2 * right);
            else if (right > left) 
                left = right = 0;
        }
        
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            if (s[i] == '(') 
                left++;
            else 
                right++;
            
            if (left == right) 
                maxlength = max(maxlength, 2 * left);
            else if (left > right) 
                left = right = 0;
        }
        return maxlength;
    }
};
