class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();
        vector<vector<int>> dp (size1,vector<int> (size2,0));

        for(int i=0; i<size1; i++) {
            if(text1[i]==text2[0])
                dp[i][0]=1;

            if(i>0)
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }

        for(int j=0; j<size2; j++) {
            if(text2[j]==text1[0])
                dp[0][j]=1;

            if(j>0)
                dp[0][j] = max(dp[0][j],dp[0][j-1]);
        }

        for(int i=1;i<size1;i++){
            for(int j=1;j<size2;j++){
                
                if(text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[size1-1][size2-1];
    }
};