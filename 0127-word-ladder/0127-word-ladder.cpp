class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len= beginWord.length();
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        if(!st.count(endWord)) return 0;

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If target word is found, return steps
            if (word == endWord) return steps;

            // Try changing every character in the current word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If no sequence exists
        return 0;
    }
};