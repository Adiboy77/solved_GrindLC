class Solution {
    /*
    Bellman Ford Understand:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
        const int INF = 1e9;
        vector<vector<int>> dp(K + 2, vector<int>(n, INF));
        dp[0][s] = 0;        
         for (int i = 1; i <= K + 1; ++i) {
            dp[i][s] = 0;
            for (const auto& x : flights)
                  dp[i][x[1]] = min(dp[i][x[1]], dp[i-1][x[0]] + x[2]);    
            }
            return dp[K + 1][d] >= INF ? -1 : dp[K + 1][d];
            
        } 
    */
public:
    //BFS:
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        int ans=INT_MAX;
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops=0;
        while(stops<=k && !q.empty()) {
            int n=q.size();
            while(n--) {
                int cnode=q.front().first;
                int cdist=q.front().second;
                q.pop();
                if(cdist>dist[cnode]) continue;
                dist[cnode]=cdist;
                for(auto e : graph[cnode]) {
                    if(e.second+cdist>ans) continue;
                    if(e.first==dst) ans=min(ans, e.second+cdist);
                    q.push({e.first, e.second+cdist});
                }
            }
            stops++;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
