class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int n1=flights[i][0];
            int n2=flights[i][1];
            int d= flights[i][2];

            adj[n1].push_back({n2,d});
        }
        vector<int> dis(n+1,INT_MAX);
        dis[src]=0;

        queue<pair<int,pair<int,int>>> q;
        // {steps,{node,distance}}
        q.push({0,{src,0}});

        while(!q.empty()){
            auto t=q.front();

            int parent=t.second.first;
            int steps=t.first;
            int d=t.second.second;

            q.pop();

            for(auto child:adj[parent]){
                int child_node=child.first;
                int wt=child.second;

                if(steps+1 <= k+1 && d+wt<dis[child_node]){
                    dis[child_node]=d+wt;
                    q.push({steps+1,{child_node,dis[child_node]}});
                }
            }
        }

        if(dis[dst]==INT_MAX)return -1;

        return dis[dst];
    }
};