class Solution {
public:
    /* Own Code
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int oranges = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] != 0)
                    oranges++;
            }
        }
        int cmp = 0, ans = 0;
        while(!q.empty())
        {
            int k = q.size();
            cmp+=k;
            while(k--)
            {
                 int r = q.front().first, c = q.front().second;
                q.pop();
                if(r<n-1 && grid[r+1][c]==1) 
                {
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                }
                if(c<m-1 && grid[r][c+1]==1) 
                {
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                }
                if(r>0 && grid[r-1][c]==1) 
                {
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                }
                if(c>0 && grid[r][c-1]==1) 
                {
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                }
            }
           if(!q.empty()) 
               ans++;
        }
       
        return cmp == oranges ? ans : -1;
    }
    */
    //Striver's clean code:
       int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }

};
