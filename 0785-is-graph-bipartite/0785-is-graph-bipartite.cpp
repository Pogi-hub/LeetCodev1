class Solution {
public:
    bool check(vector<vector<int>>& graph,int node_start,int n){
        queue<int> q;
        q.push(node_start);
        int colour[n];
        for(int &i:colour) i=-1;
        colour [node_start]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:graph[node]){
                if(colour[it]==-1){
                    colour[it]= !colour[node];
                    q.push(it);
                }
                else if(colour[it]==colour[node]){
                    return false;
                }
            }
            
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // linear graph with no cycle is always bipartite
        // a graph with a cycle that has odd no of nodes is not bipartite
        int n=graph.size();

        for(int i=0;i<n;i++){
            if(!check(graph,i,n)) return false;
        }

        return true;
    }
    
};