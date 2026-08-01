class Solution {
public:
    int reverse(int x) {
        int nx=0;
        int d;

        while(x!=0){
            d=x%10;
            if(nx+d/10>INT_MAX/10 || nx+d/10<INT_MIN/10) return 0;
            nx=nx*10+d;
            x/=10;
        }

        return nx;
    }
};