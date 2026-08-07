class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> res;
        int n=series1.size();
        int m=series2.size(); int i=0,j=0;

        while(i<n && j<m){
            int val1=0,val2=0;
            int timestamp;

            if(series1[i][0]<=series2[j][0]){
                timestamp=series1[i][0];
                val1=series1[i][1];
                i++;

                if(series2[j][0]==timestamp){
                    val2=series2[j][1]; j++;
                }
                else{
                    if(j<m) val2=series2[j][1];
                    else val2=0;
                }
            }
            else{
                timestamp=series2[j][0];
                val2=series2[j][1];
                j++;

                if(i<n) val1=series1[i][1];
                else val1=0;
            }

            res.push_back({timestamp,val1+val2});
        }

        while(i<n){
            res.push_back({series1[i][0],series1[i][1]});
            i++;
        }

        while(j<m){
            res.push_back({series2[j][0],series2[j][1]});
            j++;
        }

        return res;
    }
};