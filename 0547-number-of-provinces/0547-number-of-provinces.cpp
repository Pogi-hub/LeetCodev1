class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
    vis[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] && !vis[j]) {
            dfs(j, vis, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int count=0;

        // vector<vector<int>> adj(n);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1)
        //             adj[i].push_back(j);
        //     }
        // }

        for(int i=0;i<n;i++){
            if(!vis[i]) {
                dfs(i,vis,isConnected);
                count++;
            }
        }

        return count;

    }
};