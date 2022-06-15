/*
own code:
 vector<vector<int>> insert(vector<vector<int>>& grid, vector<int>& ni) {
        
        int n = grid.size();
        vector<vector<int>> out;
        if(n==0)
        {
            out.push_back(ni);
            return out;
        }
           if(n == 1)
        {
               if(ni[0] > grid[0][1])
               {
                    out.push_back(grid[0]);
                   out.push_back(ni);
                   return out;
               }
               if(ni[1] < grid[0][0])
               {
                     out.push_back(ni);
                   out.push_back(grid[0]);
                   return out;
               }
            out.push_back({min(ni[0],grid[0][0]),max(ni[1],grid[0][1])});
            return out;
        } 
        int l = ni[0], h = ni[1];
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] > h)
            {
                for(int j = 0;j<i;j++)
                    out.push_back(grid[j]);
                out.push_back(ni);
                for(int j=i;j<n;j++)
                {
                    out.push_back(grid[j]);
                }
                return out;
            }
            else if(l > grid[i][1])
            {
               continue;
            }
            else
            {
                grid[i][0] = min(l,grid[i][0]);
                grid[i][1] = max(h,grid[i][1]);
                flag = 1;
                break;
            }
        }
        
        if(flag)
        {
            for(int i=1;i<n;i++)
            {
                if(grid[i][0] > grid[i-1][1])
                {
                    if(out.size()==0 || out.back()!=grid[i-1])
                    out.push_back(grid[i-1]);
                    if(out.size()==0 || out.back()!=grid[i])
                    out.push_back(grid[i]);
                }
                  else
                  {
                      int hj = out.size();
                      if(hj>0)
                      {
                             out[hj-1][0] = min(grid[i-1][0],grid[i][0]);
                      out[hj-1][1] = max(grid[i-1][1],grid[i][1]);
                      }
                     
                      grid[i][0] = min(grid[i-1][0],grid[i][0]);
                      grid[i][1] = max(grid[i-1][1],grid[i][1]);
                      if(hj==0 || out.back()!=grid[i])
                      out.push_back(grid[i]);
                      
                  }
            }
        }
        else
        {
            out = grid;
            out.push_back({ni[0],ni[1]});
        }
        return out;
    }
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t i = 0;
        
        // Left part (no intersection with newInterval)//newInterval is at right, intervals at left
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        
        // newInterval part (with or without merge)
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        
        // Right part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][0] > newInterval[1]) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};
