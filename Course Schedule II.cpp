//Used topological sort using DFS, can also use topological sort using BFS also known as Kahn's algorithm
class Solution {
public:
     void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) 
     {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);//pushing the current node in stack, if all its adjacent nodes are visited
  }

    vector < int > topoSort(int N, vector < int > adj[]) {
      stack < int > st;
      vector < int > vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;

    }
 bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
    bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
      memset(vis, 0, sizeof vis);
      memset(dfsVis, 0, sizeof dfsVis);

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          // cout << i << endl; 
          if (checkCycle(i, adj, vis, dfsVis)) {
            return true;
          }
        }
      }
      return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        
        vector<int> adj[numCourses];
        int n = pr.size();
        for(int i=0;i<n;i++)
        {
            adj[pr[i][1]].push_back(pr[i][0]);
        }
        if(isCyclic(numCourses,adj))//try to check this cycle inside the topological sort function only somehow, by maintaining a visited array or anything
            return {};
        vector<int> out = topoSort(numCourses,adj);
        return out;
    }
};
