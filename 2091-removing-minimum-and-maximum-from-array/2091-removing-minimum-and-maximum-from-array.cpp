class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int i=max_element(nums.begin(),nums.end())-nums.begin();
        int j=min_element(nums.begin(),nums.end())-nums.begin();
        
        int a=min(i,j);
        int b=max(i,j);

        return min({b+1,n-a,a+1+n-b});
    }
};