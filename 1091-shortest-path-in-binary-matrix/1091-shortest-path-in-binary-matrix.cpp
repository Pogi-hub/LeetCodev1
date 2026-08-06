class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //out of all the 0's i have to find the shortest path from 0's
        if(grid[0][0]==1) return -1;
        int n=grid.size();

        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=0;

        queue<pair<int,int>> q;
        q.push({0,0});

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int dxy[4]={-1,-1,1,1};
        int dyx[4]={1,-1,1,-1};

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int x=top.first;
            int y=top.second;

            //4 directional straight
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                    if(dis[x][y]+1<dis[nx][ny]){
                        dis[nx][ny]=dis[x][y]+1;
                        q.push({nx,ny});
                    }
                }

            }
            //4 directional diagonal
            for(int i=0;i<4;i++){
                int nx=x+dxy[i];
                int ny=y+dyx[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                    if(dis[x][y]+1<dis[nx][ny]){
                        dis[nx][ny]=dis[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }//while

        if(dis[n-1][n-1]==INT_MAX) return -1;

        return dis[n-1][n-1]+1;
    }
};