class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1;
        int ans = INT_MIN;

        // Traverse from both left and right
        for (int i = 0; i < n; i++) {

            // Reset prefix & suffix if zero
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;

            pre *= nums[i];
            suff *= nums[n-i-1];

            // Update the maximum of all products seen so far
            ans = max(ans, max(pre, suff));
        }

        // Return the final answer
        return ans;
    }
    
};