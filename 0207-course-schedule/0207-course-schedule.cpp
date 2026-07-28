class Solution {
public:
    bool isCyclic(vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis,int node){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                if(isCyclic(adj,vis,pathvis,it)==true) return true;
            }
            else if(pathvis[it]) return true;
        }

        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);

        for(auto &i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(isCyclic(adj,vis,pathvis,i)) return false;
            }
        }
        return true;
    }
};