class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0,odd=0;
        int flag=1;//1-even
        while(n){
            if(flag==1) even+=1&n;
            else odd+=1&n;
            flag=3-flag;
            n/=2;
        }
        return {even,odd};
    }
};