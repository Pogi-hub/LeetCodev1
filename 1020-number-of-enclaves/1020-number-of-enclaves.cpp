class Solution {
public:
    using v=vector<int>;
    using vv=vector<v>;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    void bfs(int i,int j,vv & grid){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int >> q;
        q.push({i,j});
        grid[i][j]=0;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1) {
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
    if(grid[i][0]==1) bfs(i,0,grid);
    if(grid[i][n-1]==1) bfs(i,n-1,grid);
}

for(int j=0;j<n;j++){
    if(grid[0][j]==1) bfs(0,j,grid);
    if(grid[m-1][j]==1) bfs(m-1,j,grid);
}

        int count=0;
        for(auto row:grid){
            for(int col:row){
                if(col==1) count++;
            }
        }

        return count;
    }
};