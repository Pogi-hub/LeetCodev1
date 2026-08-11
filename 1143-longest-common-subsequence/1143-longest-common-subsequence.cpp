class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();
        vector<int> prev(size2,0);
        vector<int> curr(size2,0);

        //initialising prev array dp
        for(int j=0; j<size2; j++) {
            if(text2[j]==text1[0])
                prev[j]=1;

            if(j>0)
                prev[j] = max(prev[j],prev[j-1]);
        }

        for(int i=1;i<size1;i++){
            for(int j=0;j<size2;j++){
                if(text1[i]==text2[j]){
                curr[j]=(j>0 ? prev[j-1]:0) + 1;
                } else {
                curr[j]=max(prev[j], j>0?curr[j-1] : 0);
                }
            }
            prev=curr;
        }

        return prev[size2-1];
    }
};