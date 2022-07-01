//We can avoid using keywords: static and const in our comparator if we declare it outside here above the class

/*
Explanation: Only 3 cases are possible:
// Case 1:-
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:-
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:-
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//     --------------

*/
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);//Just was missing this, i.e in this we have to sort in increasing order of finishing times, instead of increasing order of starting times.
        int ans = 0, n = v.size();
        int cmpStart = v[0][0], cmpEnd = v[0][1];
        for(int i = 1; i < n ; i++)
        {
            if(v[i][0] >= cmpEnd)
            {
                cmpStart = min(cmpStart,v[i][0]);
                cmpEnd = max(cmpEnd, v[i][1]);
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
