class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        unordered_map<int,int> mp;
        mp[5]=0;
        mp[10]=0;
        for(int i=0;i<n;i++){
            if(bills[i]==20){
                if(mp[10]>=1 && mp[5]>=1){
                    mp[10]--; mp[5]--;
                }
                else if(mp[5]>=3){
                    mp[5]-=3;
                }
                else return false;
            }
            else if (bills[i]==10){
                if(mp[5]>=1) {
                    mp[5]--;
                    mp[10]++;
                }
                else return false;
            }
            else {
                mp[5]++;
            }
        }
        return true;
    }
};