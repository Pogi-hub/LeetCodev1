class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool allzeroes=true;
        int totalXOR=0;

        for(int x:nums){
            totalXOR^=x;
            if(x>0) allzeroes=false;
        }

        if(totalXOR!=0) return n;

        else return allzeroes?0:n-1;
    }
};