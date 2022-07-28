//See this: https://leetcode.com/problems/accounts-merge/discuss/172568/Beats-99.18-solution-C%2B%2B
//Using union find dsu:
class Solution {
    vector<int> par;
    
    int find(int nodeid) { 
        // par[nodeid] == nodeid is the leader, representative of the group
        if (par[nodeid] != nodeid)
            par[nodeid] = find(par[nodeid]);  // set the ancestor
        
        return par[nodeid];
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Union-find every user other than every email, this is the key, it is much faster than union-find emails
        // The complexity should be O(A n), O(A log n) (union by rank), or O(A \alpha(n)) (path compression), where n is size of accounts
        par = vector<int>(accounts.size()); 
        unordered_map<string, int> em2id;  // email to union-find id, so we can easily group it
        
        for (int i = 0; i < accounts.size(); ++i) {
            par[i] = i;  // init union-find
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (em2id.find(accounts[i][j]) != em2id.end())  // this email already seen, so union this i with previous seen
                    par[find(em2id[accounts[i][j]])] = i;/*  // Note: It is IMPORTANT to update parents[findParent(...)] = i
                    // instead of parents[i] = findParent(...)
                    // The reason is, when iterating the elements in the same accounts[i],
                    // doing parents[i] = findParent(...) will cause
                    // the same parents[i] updated to different values, and will loose information
                    // about the fact that all elements in this loop belongs to the same
                    // account*/
                else  // this email not seen, we set it point to parent of i
                    em2id[accounts[i][j]] = par[i];
            }
        }
        
        unordered_map<int, vector<string>> newaccs;
        for (auto &e: em2id)  // group by union-find set
            newaccs[find(e.second)].emplace_back(e.first);
        
        vector<vector<string>> res;  // construct result
        for (auto &a: newaccs) {
            auto &emails = a.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[a.first][0]);
            res.emplace_back(emails);
        }
        return res;
    }
};
