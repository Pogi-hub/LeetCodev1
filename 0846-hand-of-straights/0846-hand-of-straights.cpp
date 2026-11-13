class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(int i:hand) mp[i]++;
        for(auto it: mp){
            if(mp[it.first]>0){
                for(int i=groupSize-1;i>=0;--i){
                    if((mp[it.first+i] -= mp[it.first])<0)
                    return false;
                }
            }
        }
        return true;
    }
};