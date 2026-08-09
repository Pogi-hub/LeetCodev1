class Solution {
public:
    int recurse (vector<vector<int>>& grid,
                int steps,int r1,int r2,
                vector<vector<vector<int>>> &dp){
        
        //start case
        if(steps==0) return grid[0][0];//starting point
        //boundaries
        if(r1<0 || r2<0 || steps-r1<0 || steps-r2<0) return -1e9;//going out of grid 
        //if obstacle
        if(grid[r1][steps-r1]==-1 ||grid[r2][steps-r2]==-1) return -1e9;

        if(dp[steps][r1][r2]!=-1) return dp[steps][r1][r2];
        
        //cherries pick
        int cherries=0;
        if(r1==r2) cherries+=grid[r1][steps-r1];
        else cherries+=grid[r1][steps-r1]+grid[r2][steps-r2];
        
        int p1=recurse(grid,steps-1,r1-1,r2,dp);//path1={up,left}
        int p2=recurse(grid,steps-1,r1-1,r2-1,dp);//path2=up,up
        int p3=recurse(grid,steps-1,r1,r2,dp);//path3=left,left
        int p4=recurse(grid,steps-1,r1,r2-1,dp);//path4=left,up

        return dp[steps][r1][r2]=cherries+max(max(p1,p2),max(p3,p4));

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int> > > dp(2*n-1,vector<vector<int>>(n,vector<int> (n,-1)));
        int ans=recurse(grid,2*n-2,n-1,n-1,dp);
        if(ans<0) return 0;
        return ans;
    }
};