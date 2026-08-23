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
                if(ult_parentU == ult_parentV) return;
                //already exists in same component
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
        int removeStones(vector<vector<int>>& stones) {
            int n=stones.size();
            int totalNodes=0;
            int maxRow=0;
            int maxCol=0;
            for(auto stone:stones){
                maxRow=max(maxRow,stone[0]);
                maxCol=max(maxCol,stone[1]);
            } totalNodes=maxRow+maxCol+2;
            DisjointSet d(totalNodes);
            
            unordered_set<int> nodes;

            for(auto stone:stones){
                int row=stone[0];
                int col=stone[1]+maxRow+1;

                d.mergeByRank(row,col);

                nodes.insert(row);
                nodes.insert(col);
            }

            int components=0;
            for(auto node:nodes){
                if(d.findUparent(node)==node) components++;
            }

            return n-components;
        }
};