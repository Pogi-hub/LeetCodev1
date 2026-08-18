class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(auto edge:edges){
            dis[edge[0]][edge[1]]=edge[2];
            dis[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0;i<n;i++)    dis[i][i]=0;

        //flloyd warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }

        int citycount=n;
        int city_no=-1;

        for(int city=0;city<n;city++){
            int count=0;
            for(int adj_city=0;adj_city<n;adj_city++){
                if(dis[city][adj_city]<=distanceThreshold) count++;
            }
            if(count<=citycount){
                citycount=count;
                city_no=city;
            }
        }

        return city_no;
    }
};