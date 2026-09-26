class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans; string text="";
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        for(int i=0;i<s.size();i++){
            if(s[i]!='(')   ans+=s[i];
            else{
                i++;
                while(s[i]!=')'){
                    text+=s[i++];
                }
                if(mp.count(text))
                    text=mp[text];
                else text='?';
                ans+=text;
                text="";
            }
        }
        return ans;
    }
};