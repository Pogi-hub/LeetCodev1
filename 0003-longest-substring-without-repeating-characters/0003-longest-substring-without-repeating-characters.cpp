class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int j = 0;
        int ans = 0;

        unordered_map<char,int> mp;

        for (int i = 0; i < s.size(); i++) {

            if (mp.find(s[i]) != mp.end()) {
                j=max(j,mp[s[i]]+1);
            }

            mp[s[i]]=i;

            mx=i-j+1;

            ans=max(ans,mx);
        }

        return ans;
    }
};