class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st; int n=nums.size();
        vector<int> ans(n);

        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(st.top()>nums[i]){
                    ans[i]=st.top();
                    break;
                }
                st.pop();
            } if(st.empty()) ans[i]=-1;
            st.push(nums[i]);
        }
        return ans;
    }
};