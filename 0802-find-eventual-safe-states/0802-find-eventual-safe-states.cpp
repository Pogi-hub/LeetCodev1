class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map <int,int> outDegree;
        int n=graph.size();
        queue<int> q;
        vector<int> ans;

        //make inadjacency list
        vector <vector<int> > in_adj(n);
        for(int i=0;i<graph.size();i++){
            for(int node: graph[i]){
                in_adj[node].push_back(i);
            }
        }
        
        //calculate outdegree of all nodes
        for(int i=0;i<n;i++){
            for(auto node:graph[i]){
                outDegree[i]++;
            }
            if(outDegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);

            for(int i:in_adj[node]){
                if(--outDegree[i]==0) q.push(i);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;

    }
};