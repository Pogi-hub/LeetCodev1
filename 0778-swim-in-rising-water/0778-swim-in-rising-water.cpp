class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto [cost, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if(x == n-1 && y == n-1)
                return cost;

            if(cost > dist[x][y])
                continue;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                int newCost = max(cost, grid[nx][ny]);

                if(newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }

        return -1;
    }
};