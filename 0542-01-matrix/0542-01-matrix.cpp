class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> ans(m,vector<int> (n,-1));
        queue<pair<int,int >> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) { 
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;

                if(nx>=0 && ny>=0 && nx<m && ny<n && ans[nx][ny]==-1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        return ans;
    }
};