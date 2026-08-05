class Solution {
public:
    int lessthan_k_distinct(vector<int>& nums, int k){
        if(k<=0) return 0;
        unordered_map<int,int> freq;
        int l=0,count=0;
        int len=nums.size();

        for(int r=0;r<len;r++){
            // storing freq of elements
            if(!freq.count(nums[r])) freq[nums[r]]=1;
            else freq[nums[r]]++;
            
            while(freq.size()>k && l<len){
                if(freq[nums[l]]>1) freq[nums[l]]--;
                else freq.erase(nums[l]);
                l++;
            }

            count+=r-l+1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessthan_k_distinct(nums,k)-lessthan_k_distinct(nums,k-1);
    }
};