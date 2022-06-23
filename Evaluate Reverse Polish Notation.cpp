//Reverse Polish Notation(RPN) is also known as postfix notation where operators are after the operands
//Polish Notation(PN) is known as prefix notation where operators are before the operands
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            if(tokens[i].length() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
            {
                char c = tokens[i][0];
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                int res;
                if(c == '+')
                    res = x+y;
                else if(c == '-')
                    res = y-x;
                else if(c == '*')
                    res = x*y;
                else
                    res = y/x;
               
                stk.push(res);
            }
            else
            {
                stk.push(stoi(tokens[i]));
            }
        }
        return n == 1 ? stoi(tokens[0]) : stk.top();
    }
};
