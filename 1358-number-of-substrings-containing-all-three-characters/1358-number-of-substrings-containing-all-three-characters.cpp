class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        mp['a']=0,mp['b']=0,mp['c']=0;
        int count=0,l=0;

        // a b c a b c 
        int len=s.size();

        for(int r=0;r<len;r++){
            mp[s[r]]++;

            while(mp['a']>0 && mp['b']>0 && mp['c']>0 && l<len){
                mp[s[l]]--;
                l++;
            }

            count+=r-l+1;
        }   
        long long ans=(((long long)len*((long long)len+1))/2)-count;
        return (int) ans;
    }
};