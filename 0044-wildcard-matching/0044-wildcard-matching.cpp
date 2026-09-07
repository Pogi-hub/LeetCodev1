class Solution {
public:
    bool isallStars(string &p,int end){
        for(int i=0;i<=end;i++){
            if(p[i]!='*') return false;
        }
        return true;
    }
    bool recurse(int i, int j,string &s, string &p,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return isallStars(p,j); //text exhausted
        if(j<0 && i>=0) return false;           //pattern exhaused

        if(dp[i][j]!=-1) return dp[i][j];

        //equal characters
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=recurse(i-1,j-1,s,p,dp);

        //i am done with pattern || i am done with text
        if (p[j]=='*') return dp[i][j]= 
                              recurse(i-1,j,s,p,dp) || //done with text
                              recurse(i,j-1,s,p,dp);   //done with pattern
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();int m=p.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return recurse(n-1,m-1,s,p,dp);
    }
};