class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
     //Tree is a graph with no cycles and only a single connected component.
     bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
       vector<int> vis(n, 0);
       vector<int> adj[n];
       int n1 = edges.size();
       int connectedComponents = 0;
       for(int i = 0; i < n1; i++)
       {
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                connectedComponents++;
                if (checkForCycle(i, n, adj, vis))//may avoid sending V
                    return false;//false because if cycle then not a tree
            }
        }
        return connectedComponents == 1;
    }
};
