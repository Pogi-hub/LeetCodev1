class Solution {
public:
    int hashmap_approach(vector<int>& nums, int goal){
        int prefix=0;
        int len=nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0;

        for(int x:nums){
            prefix+=x;

            if(mp.count(prefix-goal))
            ans+=mp[prefix-goal];

            mp[prefix]++;
        }

        return ans;
    }
    int maxSum_lessthanGoal(vector<int>& nums, int goal){

        if(goal<0) return 0;

        int sum=0,count=0,l=0,r=0;
        int len=nums.size();

        for(r=0;r<len;r++){
            sum+=nums[r];

            while(sum>goal && l<len){
                sum-=nums[l];
                l++;
            }

            count+=(r-l+1);
        }

        return count;
        
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // return maxSum_lessthanGoal(nums,goal)-maxSum_lessthanGoal(nums,goal-1);
        return hashmap_approach(nums,goal);
    }
    
};