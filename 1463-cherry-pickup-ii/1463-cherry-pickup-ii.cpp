class Solution {
public:
    int recurse(vector<vector<int>>& grid,
                vector<vector<vector<int>>> &dp,
                int r,int c1,int c2                 //states
                ){

        if(r==grid.size()) return 0;
        //boundaries
        if(c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size()) return -1e9;

        //dp 
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];

        //collect cherries
        int cherries=0;
        if(c1==c2) cherries=grid[r][c1];
        else cherries=grid[r][c1]+grid[r][c2];

        //possiblities
        int path=INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                path=max(path,recurse(grid,dp,r+1,c1+i,c2+j));
            }
        }
        cherries+=path;

        //return 
        return dp[r][c1][c2]=cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return recurse(grid,dp,0,0,cols-1);
    }
};