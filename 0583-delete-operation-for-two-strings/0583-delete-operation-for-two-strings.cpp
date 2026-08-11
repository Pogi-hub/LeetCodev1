class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        vector<int> prev(len2,0);
        vector<int> curr(len2,0);

        for(int i=0;i<len2;i++){
            if(word2[i]==word1[0]) prev[i]=1;
            else if(i>0) prev[i]=max(prev[i-1],prev[i]);
        }

        for(int i=1;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(word1[i]==word2[j]){
                    curr[j]=(j>0?prev[j-1]:0)+1;
                }
                else{
                    curr[j]=(j>0?max(curr[j-1],prev[j]):prev[0]);
                }
            }
            prev=curr;
        }

        int common_subseq=prev[len2-1];
        int ans=(len1-common_subseq)+(len2-common_subseq);
        return ans;
    }
};