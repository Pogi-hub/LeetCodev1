class Solution {
public:
    string removeOuterParentheses(string s) {
        int open =0,close=0,start=0;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') ++open;
            else ++close;
            if(open==close){
                ans+=s.substr(start+1,i-start-1);
                start=i+1;
                open=close=0;
            }
        }
        return ans;
    }
};