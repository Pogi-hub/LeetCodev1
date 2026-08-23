class Solution {
    class DisjointSet{
        vector<int> rank;
        vector<int> parent;
        public:
            DisjointSet(int n){
                rank.resize(n+1,0);
                parent.resize(n+1);
                for(int i=0;i<n;i++) parent[i]=i;
            }
            int findUparent(int node){
                if(parent[node]==node) return node;
                return parent[node]=findUparent(parent[node]);
            }
            void mergeByRank(int u,int v){
                int ult_parentU=findUparent(u);
                int ult_parentV=findUparent(v);
                if(ult_parentU == ult_parentV) return;//already exists in same component
                if(rank[ult_parentU]<rank[ult_parentV])
                    parent[ult_parentU]=ult_parentV;
                else if(rank[ult_parentU]>rank[ult_parentV])
                    parent[ult_parentV]=ult_parentU;
                else{
                    parent[ult_parentV]=ult_parentU;
                    rank[ult_parentU]++;
                }
            }
    };
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {

            int extraWires=0;
            DisjointSet d(n);
            for(auto c:connections){
                if(d.findUparent(c[0])!=d.findUparent(c[1]))
                    d.mergeByRank(c[0],c[1]);
                else{
                    extraWires++;
                }
            }
            int wiresUsed=0;
            for(int i=1;i<n;i++){
                if(d.findUparent(i)==d.findUparent(i-1)) continue;

                //need extrawire to connect them
                d.mergeByRank(i,i-1);
                wiresUsed++;
            }
            if(wiresUsed>extraWires) return -1;
            return wiresUsed;
        }
};