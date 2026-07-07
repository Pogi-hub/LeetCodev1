class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0; int j=0; int ans=0;

        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                mx++;
            }
            else{
                i=mp[s[i]];
                ans=max(ans,mx);
                mx=0;
                mp.clear();
            }
            ans=max(ans,mx);
        }

        return ans;
    }
};