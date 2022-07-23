/*
Through aditya verma playlist:
find NSL and NSR of each index using stack of pairs & psuedo indices of -1 for no NSL and n for no NSR
find width as width = NSR-NSL-1
find area as area = width * arr
return max area
*/
vector<int> nextSmallerElement(vector<int>& nums) {
        stack<pair<int,int>> st;//using stack of pair to get the indices of NSE as the second and the first value as the element itself
        int n = nums.size();
        vector<int> out;
        for(int i = n-1; i >= 0 ; i--)
        {
            if(st.empty())
            {
                out.push_back(n);//pushing n as per the demand of the question
            }
            else
            {
                while(!st.empty() && st.top().first >= nums[i])//change in condition, opposite to nextGreaterElement
                    st.pop();
                if(st.empty())
                    out.push_back(n);//pushing n as per the demand of the question
                else
                    out.push_back(st.top().second);
            }
             st.push({nums[i],i});
        }
        reverse(out.begin(),out.end());//very important step
        return out;
    }

vector<int> previousSmallerElement(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n = nums.size();
        vector<int> out;
        for(int i = 0; i < n ; i++)//Opposite direction of loop
        {
            if(st.empty())
            {
                out.push_back(-1);
            }
            else
            {
                while(!st.empty() && st.top().first >= nums[i])//same condition as nextSmallerElement
                    st.pop();
                if(st.empty())
                    out.push_back(-1);
                else
                    out.push_back(st.top().second);
            }
             st.push({nums[i],i});
        }
   //Don’t reverse vector at last:very important step //Major change for previous greater/smaller      
        return out;
    }

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr = nextSmallerElement(heights);
        vector<int> nsl = previousSmallerElement(heights);
        int ans = INT_MIN;
        int n = heights.size();
        
        for(int i = 0; i < n; i++)
        {
            
            int width = nsr[i] - nsl[i] - 1;
            int length = heights[i];
            int area = width * length;
            ans = max(ans,area);
        }
        return ans;
    }
};
