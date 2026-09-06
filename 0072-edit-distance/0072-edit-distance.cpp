class Solution {
public:
    int recurse(int i,int j,string &word1,string &word2,
                vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]= 0+recurse(i-1,j-1,word1,word2,dp);
        else{
            int ins=recurse(i,j-1,word1,word2,dp);
            int del=recurse(i-1,j,word1,word2,dp);
            int rep=recurse(i-1,j-1,word1,word2,dp);
            return dp[i][j]=1+min({ins,del,rep});
        }

    }
    int minDistance(string word1, string word2) {
        int n=word1.size();int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recurse(n-1,m-1,word1,word2,dp);
    }
};