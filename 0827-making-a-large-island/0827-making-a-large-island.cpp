class Solution {
public:
    class DisjointSet {
        vector<int> parent,size;
    public:
        DisjointSet(int n) {
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int node) {
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }

        void unionBySize(int u,int v) {
            int pu=find(u),pv=find(v);
            if(pu==pv) return;

            if(size[pu]<size[pv]) {
                parent[pu]=pv;
                size[pv]+=size[pu];
            } else {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }

        int getSize(int node) {
            return size[find(node)];
        }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        DisjointSet ds(n*n);

        for(int x=0;x<n;x++) {
            for(int y=0;y<n;y++) {
                if(grid[x][y]==0) continue;

                for(int k=0;k<4;k++) {
                    int nx=x+dx[k],ny=y+dy[k];

                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==1) {
                        ds.unionBySize(x*n+y,nx*n+ny);
                    }
                }
            }
        }

        int ans=0;

        for(int x=0;x<n;x++) {
            for(int y=0;y<n;y++) {
                if(grid[x][y]==1) continue;

                int totalSize=1;
                unordered_set<int> parents;

                for(int k=0;k<4;k++) {
                    int nx=x+dx[k],ny=y+dy[k];

                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==1) {
                        parents.insert(ds.find(nx*n+ny));
                    }
                }

                for(int p:parents)
                    totalSize+=ds.getSize(p);

                ans=max(ans,totalSize);
            }
        }

        for(int x=0;x<n;x++) {
            for(int y=0;y<n;y++) {
                if(grid[x][y]==1)
                    ans=max(ans,ds.getSize(x*n+y));
            }
        }

        return ans;
    }
};