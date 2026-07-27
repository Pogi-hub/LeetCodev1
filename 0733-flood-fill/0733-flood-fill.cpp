class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int original_color){
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int n=image.size();
        int m=image[0].size();

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if(image[nx][ny]==original_color){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color=image[sr][sc];

        //caused infinite loop
        if (original_color == color)
            return image;

        image[sr][sc]=color;
        bfs(image,sr,sc,color,original_color);
        return image;
    }
};