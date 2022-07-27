//Done on own:
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
//Understanding question: schedule input array is the busy intervals of people, & we have to output all of the finite common free intervals of people
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<int>> &v) {
        vector<Interval> out;
        vector<pair<int,int>> vp;
        int n = v.size();
        for(int i = 0; i < n; i++)
        {
            int sz = v[i].size();
            for(int j = 0; j < sz-1; j+=2)
            {
                vp.push_back({v[i][j],v[i][j+1]});
            }
        }
        sort(vp.begin(),vp.end());
        int ns = vp.size();
        if(ns < 2)
            return out;
        int mini = vp[0].first, maxi = vp[0].second;
        for(int i = 1; i < ns; i++)
        {
            if(vp[i].first > maxi)
            {
                out.push_back(Interval(maxi,vp[i].first));//was writing this Interval syntax wrong initially
                maxi = vp[i].second;
            }
            else
            {
                maxi = max(maxi,vp[i].second);
            }
        }
        return out;
    }
};
