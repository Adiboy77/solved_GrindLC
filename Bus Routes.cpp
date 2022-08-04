//https://www.youtube.com/watch?v=R58Q0J52qzI
/*
Note that this question is asking least number of buses, & not the least number of stops
So BFS here would be slightly different
In stop_routes, key is the stop number, and value is the different paths in which the key stop can exist.
Our queue would be of a pair, in which the first means the stop which we are on, & the second would give the number of different buses taken upto at that point
Now after pushing certain stops/paths in our queue, we clear it from the graph, as we don't need them because we only need the unique number of paths ie buses
We would do this, until we find our destination stop
And say if the input graph becomes empty at some point, then also we simply pop from the queue until we get our destination
Throughout this, we increment the second of the pair that we are pushing in queue by 1, ie the distance and the reason that this works is that we are clearing the buses with their paths from the input graph so increasing distance at each step certainly means that we have taken a new bus
Time: O(N) + O(x): x is the total length of vector of vectors as we are inserting in unordered_map
Space: O(N)
*/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
       unordered_map<int, unordered_set<int>> stop_routes;
   
       for (int i = 0; i < routes.size (); ++i) 
          for (int j : routes[i]) stop_routes[j].insert (i);

       queue<pair<int, int>> to_visit; 
       to_visit.push ({ S, 0 });
       unordered_set<int> stops_visited = { S };

       while (!to_visit.empty ()) 
       {
          int stop  = to_visit.front ().first;
          int bus_n = to_visit.front ().second;

          if (stop == T) return bus_n;
          to_visit.pop ();

          for (const auto& route : stop_routes[stop]) {
             for (const auto& next_stop : routes[route]) 
             {
                auto it = stops_visited.insert (next_stop);
                if (it.second) // this gives true, if in the previous line we have not visited that stop yet
                    to_visit.push ({ next_stop, bus_n + 1 });              
             }

             routes[route].clear ();//very important, else will give TLE
          }
       }

       return -1;
    }
};
