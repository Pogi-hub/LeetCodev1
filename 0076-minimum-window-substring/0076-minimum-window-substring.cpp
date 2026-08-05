class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map <char,int> ft;
        unordered_map <char,int> fs;

        int len_s=s.size();
        int len_t=t.size();

        string ans="";
        int l=0;
        int isTrue=0;
        int start = 0;
        int minLen = INT_MAX;

        //creating map of characters in string t
        for(char ch:t){
            ft[ch]++;
        }

        for(int r=0; r<len_s; r++){
            char c=s[r];
            
            //increasing the frequency of stored elements in s
            fs[c]++;

            //incrementing isTrue if the element overlaps in both strings
            if( ft.count(c) && fs[c]<=ft[c] ) isTrue++;

            while(isTrue == len_t){
                // CHANGED
                // Update answer ONLY when window is valid
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    start=l;
                }

                char a = s[l];

                // CHANGED
                // Removing this character may break the window.
                if(ft.count(a) && fs[a] <= ft[a])
                    isTrue--;

                fs[a]--;
                // Optional cleanup
                if(fs[a] == 0)
                    fs.erase(a);

                l++;
            }
        }

        if(minLen==INT_MAX) return "";

        return s.substr(start,minLen);
    }
};