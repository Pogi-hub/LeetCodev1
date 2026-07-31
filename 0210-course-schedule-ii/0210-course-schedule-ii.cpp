class Solution {
public:
    bool iscyclic_dfs(vector<vector<int>>& adj,vector<bool> &vis,vector<bool> &pathvis,int node){
        vis[node]=1;
        pathvis[node]=1;

        for(int i:adj[node]){
            if(!vis[i]){
                if(iscyclic_dfs(adj,vis,pathvis,i)) return true;
            }
            else if(pathvis[i]) return true;
        }

        pathvis[node]=0;

        return false;
    }
    void print_dfs(vector<bool> & vis,vector<int> & ans,vector<vector<int>>& adj,int node){
        vis[node]=1;

        for(int i:adj[node]){
            if(!vis[i])
                print_dfs(vis,ans,adj,i);
        }

        ans.push_back(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses,0);
        vector<bool> pathvis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscyclic_dfs(adj,vis,pathvis,i)) return {};
            }
        }

        fill(vis.begin(), vis.end(), false);

        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
            print_dfs(vis,ans,adj,i);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};