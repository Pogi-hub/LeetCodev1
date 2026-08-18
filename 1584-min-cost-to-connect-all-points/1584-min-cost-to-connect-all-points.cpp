class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> vis(n, false);

        minDist[0] = 0;

        int sum = 0;

        for(int count = 0; count < n; count++) {

            // Find unvisited point with minimum connection cost
            int u = -1;

            for(int i = 0; i < n; i++) {
                if(!vis[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }

            // Add this point to MST
            vis[u] = true;
            sum += minDist[u];

            // Update distances of remaining points
            for(int v = 0; v < n; v++) {

                if(!vis[v]) {

                    int wt = abs(points[u][0] - points[v][0]) +
                             abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], wt);
                }
            }
        }

        return sum;
    }
};