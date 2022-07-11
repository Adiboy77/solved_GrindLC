//Similar to next greater element
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
    stack<pair<int,int>> s;//first is array elements, second is index of element
    int n = arr.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) 
    {
            if (!s.empty()) 
            {
                 while (!s.empty() && s.top().first <= arr[i]) 
                 {
                    s.pop();
                 }
            }
        res[i] = s.empty() ? 0 : s.top().second - i;//was pushing just s.top.second here, but we don't need the index of next greater element, instead we need the distance of next greater elemnt from the current position so that why we do - i.
        s.push({arr[i],i});
    }
      return res;
    }
};
