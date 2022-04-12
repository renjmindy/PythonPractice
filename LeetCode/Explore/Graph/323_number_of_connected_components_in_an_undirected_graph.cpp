class Solution {
public:
    //convert the graph into adjacency list first 
    //number of dfs is the number of components
    
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;
        
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                dfs(adj[node][i], visited, adj);
            }
        }        
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int ans = 0;
        
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, visited, adj);
            }            
        }
        return ans;
    }
};
