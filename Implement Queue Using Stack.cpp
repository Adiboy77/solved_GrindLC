class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ans;
        if(!output.empty())
        {
            ans = output.top();
            output.pop();
            return ans;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            ans = output.top();
            output.pop();
        }
        return ans;
    }
    
    int peek() {
        if(!output.empty())
            return output.top();
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        else
            return false;
    }
};
//Time: push: O(1), pop:AmortizedO(1), peek and empty: O(1)
//Space: O(n)for push, O(1) for pop, peek and empty
