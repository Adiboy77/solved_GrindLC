//First the max heap based ordering is decided by frequency and then by count,
class FreqStack {
    priority_queue<pair<int, pair<int, int>>> q;//first stores frequency, second.first stores position, i.e. higher the position, higher the element is in the stack , i.e more close to top & second.second stores the element itself
    unordered_map<int, int> freq;//stores the element & its frequency
    int pos = 0;
public:
    void push(int x) 
    {
        freq[x]++;
        pos++;
        q.push({freq[x] , {pos,x}});
    }
    
    int pop() {
        auto val = q.top();
        q.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};
