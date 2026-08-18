class Solution {
public:
    using p=pair<int,int>;
    struct pairHash {
        size_t operator()(const p& a) const {
            return hash<int>()(a.first) ^ (hash<int>()(a.second) << 1);
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int sum=0;
        unordered_map<p, vector<p>, pairHash> adj;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                adj[{x1,y1}].push_back({x2,y2});
                adj[{x2,y2}].push_back({x1,y1});
            }
        }
        set<pair<int,int>> vis;
        set<pair<int,p>> st;
        st.insert({0,{points[0][0],points[0][1]}});

        while(!st.empty()){
            auto parent=*(st.begin());
            int p_wt=parent.first;
            int px=parent.second.first;
            int py=parent.second.second;
            st.erase(parent);

            if(vis.count({px,py})) continue;
            vis.insert({px,py});
            sum+=p_wt;

            for(auto &[cx,cy]:adj[{px,py}]){
                int wt=abs(px-cx)+abs(py-cy);
                st.insert({wt,{cx,cy}});
            }
        }

        return sum;
    }
};