class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    void bfs(int i, int j, vector<vector<char>>& board ){
        int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        board[i][j]='A';


        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();

            // board[x][y]='A'; <-this was unnecessary work which cause TLE so shift it to immediate change when pushing it in queue

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]=='O') {
                    board[nx][ny]='A';
                    q.push({nx,ny});
                    }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();


        for(int i=0;i<m;i++){
            if(board[i][0]=='O') bfs(i, 0, board);
            if(board[i][n-1]=='O') bfs(i, n-1, board);
        }
        for(int j=1;j<n-1;j++){
            if(board[0][j]=='O') bfs( 0, j, board);
            if(board[m-1][j]=='O') bfs(m-1, j, board);
        }

        for(auto &row:board){
            for(char &col : row){
                if(col=='O') col='X';
                if(col=='A') col='O';
            }
        }
    }
};