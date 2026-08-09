class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());

        vector<int> points(mx+1,0);

        for(int x:nums){
            points[x]+=x;
        }

        int prev1=0;
        int prev2=points[1];

        for(int i=2;i<=mx;i++){
            int curr=max(prev2,prev1+points[i]);
            prev1=prev2;
            prev2=curr;
        }

        return prev2;
    }
};