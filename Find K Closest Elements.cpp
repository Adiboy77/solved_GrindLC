class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), count = 0;
        vector<int> out;
        int start = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int end;
        if(start == n)
        {
            start = n-1;//mistake was initializing start with 0, and end with n-1, but instead in this case, we just need to traverse from the end of the array
            end = n;
        }
        else if(arr[start] == x)
        {
            out.push_back(arr[start]);
            end = start+1;
            start = start - 1;
            count++;
        }
        else
        {
            end = start;
            start = start - 1;
        }
        while(count<k && start>=0 && end<n)
        {
            int cmp1 = abs(arr[start]-x), cmp2 = abs(arr[end]-x);
            if(cmp1 <= cmp2)
            {
                out.push_back(arr[start]);
                start--;
                count++;
            }
            else
            {
                out.push_back(arr[end]);
                end++;
                count++;
            }
        }
        if(count < k)
        {
            if(end>=n)
            {
                while(count<k && start>=0)
                {
                    out.push_back(arr[start]);
                    start--;
                    count++;
                }
            }
            else
            {
                while(count<k && end<n)
                {
                    out.push_back(arr[end]);
                    end++;
                    count++;
                }
            }
        }
        sort(out.begin(),out.end());
        return out;
    }
};
