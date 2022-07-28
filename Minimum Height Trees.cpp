//We have .top in stack & .front in queue.
//https://www.youtube.com/watch?v=ivl6BHJVcB0
/*How many MHTs can a graph have at most?
There can be atmost 2 MHTs in a graph, 1 MHT in case of odd max. lengthed path & 2 MHTs in case of even max. lenghted path
So solution:
Find degrees of all the nodes, degree = 1 are leaves, so won't contribute to our answer
Remove leaves while decrementing the degrees of nodes attached to them.
Now we again remove degree 1 nodes while following the same approach as earlier
We do this up until we have <= 2 nodes available with us (as MHTs can be atmost 2 & we need to return all of them)
We will use BFS basically
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> out;
        if(n == 1)//was missing this edge case of just a single node with no edges
        {
            out.push_back(0);
            return out;
        }
        vector<int> deg(n , 0);
        int ne = edges.size();
        vector<int> adj[n];
        for(int i = 0; i < ne; i++)
        {
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;//Because we use BFS
        for(int i = 0; i < n; i++)
        {
            if(deg[i] == 1)
                q.push(i);
        }
        
        while(n > 2)
        {
            int qs = q.size();
            n -= qs;//Removing all degree 1 nodes at each step
            for(int i = 0; i < qs; i++)
            {
                int cur = q.front();
                q.pop();
                for(auto it: adj[cur])
                {
                    deg[it]--;
                    if(deg[it] == 1)
                        q.push(it);
                }
            }
        }
        
        while(!q.empty())
        {
            out.push_back(q.front());
            q.pop();
        }
        return out;         
    }
};
