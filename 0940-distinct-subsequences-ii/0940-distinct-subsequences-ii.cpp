class Solution {
int MOD=1e9+7;
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int> endWith(26,0);

        int sum=0;

        for(int i=0;i<n;i++){
            int idx=s[i]-'a';

            int curr=(1+sum-endWith[idx]+MOD)%MOD;
            sum=(sum+curr)%MOD;

            endWith[idx]=(endWith[idx]+curr)%MOD;
        }

        return sum;
    }
};