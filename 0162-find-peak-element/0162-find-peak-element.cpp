class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int e=nums.size()-1;
        int s=0;
        int m;
        while(s<e){
            m=s+(e-s)/2;

            if(m<e && nums[m]<nums[m+1])   s=m+1;
            else                    e=m;
        }

        return s;
    }
};