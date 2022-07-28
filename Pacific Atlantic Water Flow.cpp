//https://www.youtube.com/watch?v=s-VkcjHqkGI
/*
Top and left is pacific
Bottom and right is atlantic
So we would see in top row and left column only, that which all nodes can reach top row or left column of the matrix or in other words we would mark those nodes which can be reached from top row and left column: these would further be said to reach pacific
And then we would see in right column and bottom row only, that which all nodes can reach right column or bottom row,or in other words we would mark those nodes which can be reached from bottom row or right column: these would further be said to reach atlantic
Then at last, the common nodes of pacific and atlantic would be pushed on in the result
Time complexity is O(n*m) as in each of the traversals (pacific or atlantic), if we revisit any node, we would not continue that path because of the condition that we have that water can only flow to <= nodes.
And we will move through >= nodes as our traversals (pacific and atlantic) are opposite ie they are from literally ocean(top,left & bottom,right) to nodes(rather than nodes to ocean)
*/
class Solution {
public:
    int n,m;
    void dfs(int r, int c, set<pair<int,int>>& visited, int prevHeight, vector<vector<int>>& heights)
    {
        if(r < 0 || c < 0 || r >= n || c >= m || visited.find({r,c}) != visited.end() || heights[r][c] < prevHeight)
            return;
        visited.insert({r,c});
        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> pac, atl;
        n = heights.size(), m = heights[0].size();
        
        for(int j = 0; j < m; j++)
        {
            dfs(0, j, pac, heights[0][j], heights);//Top row pacific : 4th parameter is the prevHeight = height of current node itself, we need to pass it because we only can travel to nodes >= (opp. condition due to opp. direction of traversal ie from ocean to nodes)
            dfs(n-1, j, atl, heights[n-1][j], heights);//Bottom row atlantic
        }
        
        for(int i = 0; i < n; i++)
        {
            dfs(i, 0, pac, heights[i][0], heights);//Left column pacific
            dfs(i, m-1, atl, heights[i][m-1], heights);//Right column atlantic
        }
        
        vector<vector<int>> out;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pac.find({i,j}) != pac.end() && atl.find({i,j}) != atl.end())
                    out.push_back({i,j});
            }
        }
        return out;
    }
};
