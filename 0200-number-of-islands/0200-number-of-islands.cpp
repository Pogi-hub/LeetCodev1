class Solution {
public:
    using v=vector<int>;
    using vc=vector<char>;
    using vv=vector<v>;
    using vvc=vector<vc>;

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void bfs(vv & vis,vvc &grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int >> q;
        q.push({i,j});
        vis[i][j]=1;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && vis[nx][ny]==-1) {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // probelm is basically return total components of graph '
        int m=grid.size();
        int n=grid[0].size();
        vv vis(m,v(n,-1));
        int count =0;// no of regions = no of bfs traversals done

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){
                    bfs(vis,grid,i,j);
                    count++;
                }
            }
        }

        return count;
    }
};