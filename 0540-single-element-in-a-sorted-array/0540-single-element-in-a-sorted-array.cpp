class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mi;
        while(s<e){
            mi=s+(e-s)/2;
            if( mi%2==1) mi--;

            if(nums[mi]==nums[mi+1]) s=mi+2;
            else e=mi;
 
        }

        return nums[s];
    }
};