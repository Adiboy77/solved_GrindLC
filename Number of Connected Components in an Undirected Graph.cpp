//Just made manual changes here itself, in DFS, by including a variable comp
class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        storeDfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {//Very Very important step
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
public:
	int dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> storeDfs; 
	    vector<int> vis(V+1, 0); 
      int comp = 0;
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) 
        {
          dfs(i, vis, adj, storeDfs); 
          comp++;
        }   
      }
	    return comp; 
	}
};
