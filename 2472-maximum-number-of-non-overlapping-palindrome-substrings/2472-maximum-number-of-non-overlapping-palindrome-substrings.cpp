class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();int ans=0; int start=0;
        for(int c=0;c<2*n-1;++c){
            int l=c/2; int r=l+c%2;
            while(l>=start && r<n && s[l]==s[r]){
                if(r-l+1>=k){
                    ++ans;
                    start=r+1;
                    break;
                }
                --l;
                ++r;
            }
        }
        return ans;
    }
};