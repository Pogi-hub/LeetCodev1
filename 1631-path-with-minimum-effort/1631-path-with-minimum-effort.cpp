class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;

        priority_queue<
                pair<int, pair<int, int>>,
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>
                > pq;

        pq.push({ 0,{0,0} });

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int x=top.second.first;
            int y=top.second.second;

            int currEffort=top.first;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int edge = abs(heights[nx][ny] - heights[x][y]);
                    int newEffort = max(currEffort, edge);

                    if(newEffort < dis[nx][ny]) {
                        dis[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }//while

        return dis[n-1][m-1];
    }
};
