class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        // Check for the base case. If there are no intervals, return 0
        if (intervals.size() == 0) {
        return 0;
        }

        vector<int> start(intervals.size());
        vector<int> end(intervals.size());

        for (int i = 0; i < intervals.size(); i++) {
        start[i] = intervals[i].start;
        end[i] = intervals[i].end;
        }

        // Sort the intervals by end time
        sort(end.begin(), end.end());

        // Sort the intervals by start time
        sort(start.begin(), start.end());

        // The two pointers in the algorithm: e_ptr and s_ptr.
        int startPointer = 0, endPointer = 0;

        // Variables to keep track of maximum number of rooms used.
        int usedRooms = 0;

        // Iterate over intervals.
        while (startPointer < intervals.size()) {

        // If there is a meeting that has ended by the time the meeting at `start_pointer` starts
        if (start[startPointer] >= end[endPointer]) {
            usedRooms -= 1;
            endPointer += 1;
        }

        // We do this irrespective of whether a room frees up or not.
        // If a room got free, then this used_rooms += 1 wouldn't have any effect. used_rooms would
        // remain the same in that case. If no room was free, then this would increase used_rooms
        usedRooms += 1;
        startPointer += 1;

        }

        return usedRooms;
    }
};
