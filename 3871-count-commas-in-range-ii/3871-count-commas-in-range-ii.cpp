class Solution {
using ll=long long;
public:
    long long countCommas(long long n) {
        ll ans=0;
        for(ll i=1000;i<=n;i*=1000){
            ans+=n-i+1;
        }
        return ans;
    }
};