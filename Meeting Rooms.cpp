class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size();
        vector< pair<int,int> > vp;
        for(int i=0;i<n;i++)
        vp.push_back({intervals[i].start,intervals[i].end});
        sort(vp.begin(),vp.end());
        for(int i = 1;i<n;i++)
        {
            if(vp[i].first < vp[i-1].second)
            return false;
        }
        return true;
    }
};
