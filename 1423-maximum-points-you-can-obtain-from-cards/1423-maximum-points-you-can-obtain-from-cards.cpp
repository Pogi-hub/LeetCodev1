class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0; int ans=0;
        int len=cardPoints.size();

        for(int i=len-1;i>=len-k;i--){
            sum+=cardPoints[i];
        }

        ans=sum;

        for(int i=0;i<k;i++){
            sum-=cardPoints[len-k+i];
            sum+=cardPoints[i];

            ans=max(ans,sum);
        }

        return ans;
    }
};