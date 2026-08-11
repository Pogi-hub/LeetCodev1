class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        string text1=s;
        string text2=s;
        reverse(text2.begin(),text2.end());

        vector<int> prev(len,0);
        vector<int> curr(len,0);

        //initialising prev array dp
        for(int j=0; j<len; j++) {
            if(text2[j]==text1[0])
                prev[j]=1;

            if(j>0)
                prev[j] = max(prev[j],prev[j-1]);
        }

        for(int i=1;i<len;i++){
            for(int j=0;j<len;j++){
                if(text1[i]==text2[j]){
                curr[j]=(j>0 ? prev[j-1]:0) + 1;
                } else {
                curr[j]=max(prev[j], j>0?curr[j-1] : 0);
                }
            }
            prev=curr;
        }


        return prev[len-1];
    }
};