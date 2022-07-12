/* Revise it
My understanding:

The basic idea is every time we start from a station, we go as far as possible by increasing end until remaining gas is less than 0. If 'end' finally hits start we know we can travel around from 'start'. If we haven't traveled around, we know we cannot start from this station. Then we check the station before our start station if we can start from this station. Repeat until we have checked all stations.

Note there is a little trick that every time we try to find the next start station, we always to back to extend the distance from start to end so that we can check all stations on the circuit. Otherwise, if we move start forward to decrease the distance from start to end, we are likely to end up with only checking part of the circuit. Another trick is we start from the end of the array so as to avoid some corner cases.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};
