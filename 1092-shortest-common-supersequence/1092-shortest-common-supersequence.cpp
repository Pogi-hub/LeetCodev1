class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1=str1.size();
        int len2=str2.size();
        vector<vector<int>> dp (len1,vector<int> (len2,0));

        for(int i=0; i<len1; i++) {
            if(str1[i]==str2[0])
                dp[i][0]=1;

            if(i>0)
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }
        for(int j=0; j<len2; j++) {
            if(str2[j]==str1[0])
                dp[0][j]=1;

            if(j>0)
                dp[0][j] = max(dp[0][j],dp[0][j-1]);
        }

        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                
                if(str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        //printing the answer
        string common_subseq=""; 
        int i=len1-1; int j=len2-1;
        while(i>=0 && j>=0) {
            if(str1[i]==str2[j]) {
                common_subseq+=str1[i];
                i--;
                j--;
            }
            else if(i>0 && (j==0 || dp[i-1][j] >= dp[i][j-1])) {
                i--;
                }
            else {
                j--;
            }
        } reverse(common_subseq.begin(),common_subseq.end());
        
        string ans="";
        
        int k=0; i=0,j=0;
        while(k < common_subseq.size()) {
            while(str1[i] != common_subseq[k]) {
                ans += str1[i++];
            }

            while(str2[j] != common_subseq[k]) {
                ans += str2[j++];
            }

            ans += common_subseq[k];
            
            i++;
            j++;
            k++;
        }

        while(i < len1) ans += str1[i++];
        while(j < len2) ans += str2[j++];  

        return ans;
    }
};