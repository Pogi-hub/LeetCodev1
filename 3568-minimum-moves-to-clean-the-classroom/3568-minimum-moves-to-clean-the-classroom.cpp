class Solution {
int dir[5] = {-1,0,1,0,-1};
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();  // 1-20
        int n = classroom[0].size();  // 1-20
        int sx, sy;      
        int trash = 0; // pos -> index
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(classroom[i][j] == 'S'){
                    sx = i; sy = j;
                } else if(classroom[i][j] == 'L'){
                    classroom[i][j] = '0' + trash;
                    ++trash;
                }
            }
        }
        if(trash == 0)
            return 0;
        int bitMax = (1 << trash) - 1; 

        int maxEng[20][20][1024];
        memset(maxEng, -1, sizeof(maxEng));

        queue<tuple<int,int,int,int>> q;
        q.push({sx,sy,energy,0});
        maxEng[sx][sy][0]=energy;
        int steps=0;

        while(!q.empty()){
            int sz=q.size();
            for(int run=0;run<sz;++run){
                auto [x,y,en,mask]=q.front();
                q.pop();
                if(mask==bitMax) return steps;
                if(en==0) continue;
                for(int i=0;i<4;++i){
                    int nx=x+dir[i];
                    int ny=y+dir[i+1];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n ||            classroom[nx][ny] == 'X')
                    continue;
                    
                    int nxt_en=en-1;
                    int nxt_mask=mask;

                    if(classroom[nx][ny] == 'R')
                        nxt_en = energy;
                    else if(classroom[nx][ny]<='9' && classroom[nx][ny]>='0')
                        nxt_mask = nxt_mask | 1<<(classroom[nx][ny]-'0');
                    
                    if(maxEng[nx][ny][nxt_mask]<nxt_en){
                        maxEng[nx][ny][nxt_mask]=nxt_en;
                        q.push({nx,ny,nxt_en,nxt_mask});
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};