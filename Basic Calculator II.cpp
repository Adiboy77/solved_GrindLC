class Solution {
public:
    /*
    Intuition

In the previous approach, we used a stack to track the values of the evaluated expressions. In the end, we pop all the values from the stack and add to the result. Instead of that, we could add the values to the result beforehand and keep track of the last calculated number, thus eliminating the need for the stack. Let's understand the algorithm in detail.

Algorithm

The approach works similar to Approach 1 with the following differences :

Instead of using a stack, we use a variable lastNumber to track the value of the last evaluated expression.
If the operation is Addition (+) or Subtraction (-), add the lastNumber to the result instead of pushing it to the stack. The currentNumber would be updated to lastNumber for the next iteration.
If the operation is Multiplication (*) or Division (/), we must evaluate the expression lastNumber * currentNumber and update the lastNumber with the result of the expression. This would be added to the result after the entire string is scanned.
    */
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};
