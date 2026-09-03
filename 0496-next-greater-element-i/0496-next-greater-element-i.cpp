class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int> mp;
        stack <int> st;

        for(int i=n2-1;i>=0;i--){
            while(!st.empty()){
                if(st.top()>nums2[i]){
                    mp[nums2[i]]=st.top();
                    break;
                }
                st.pop();
            } 
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0;i<n1;i++){
            if(mp.count(nums1[i])!=0) ans.push_back(mp[nums1[i]]);
            else ans.push_back(-1);
        }

        return ans;
    }
};