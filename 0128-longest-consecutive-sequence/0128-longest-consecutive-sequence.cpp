class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;

        int ans=0;
        
        unordered_set<int> st;
        st.reserve(nums.size() * 2);
        st.max_load_factor(0.7);

        for(int x : nums)   st.insert(x);

        for(int x : st) {
            if(x != INT_MIN && st.count(x - 1))
                continue;

            int len = 1;
            int curr = x;

            while(curr != INT_MAX && st.count(curr + 1)) {
                curr++;
                len++;
            }

            ans = max(ans, len);
        }
        return ans;
    }
};