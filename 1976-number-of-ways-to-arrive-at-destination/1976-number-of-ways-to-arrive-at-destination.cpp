const int mod = 1e9 + 7;
using ll=long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto r: roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<ll> dis(n,LLONG_MAX);
        vector<ll> ways(n,0);
        dis[0]=0;
        ways[0]=1;

        priority_queue <pair<ll,int>,
                        vector<pair<ll,int>>,
                        greater<pair<ll,int>>
                        >pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            ll d = it.first; 
            int parent =it.second;
            pq.pop();

            for(auto child:adj[parent]){
                int child_node=child.first;
                ll wt=child.second;
                if(wt+d<dis[child_node]){
                    dis[child_node]=wt+d;
                    ways[child_node]=(ways[parent])%mod;
                    pq.push({dis[child_node],child_node});
                }
                else if(wt+d==dis[child_node]){
                    ways[child_node]=(ways[parent]+ways[child_node])%mod;
                }
            }
        }

        return ways[n-1]%mod;

    }
};