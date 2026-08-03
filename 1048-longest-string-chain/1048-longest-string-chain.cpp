class Solution {
public:
    static bool com(string s1, string s2) {
        return s1.size()<s2.size();
    }
    bool isPredecessor(string word1, string word2) {
        if(word1.size()+1 != word2.size())
        return 0;

        int i = word1.size(), j = word2.size();

        while(i && j) {
            if(word1[i-1] == word2[j-1])
            i--, j--;
            else 
            j--;
        }

        return i==0? 1: 0;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), com);
        int n = words.size();
        vector<int> LSC(n, 1);

        int maxLen = 1;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isPredecessor(words[j], words[i])) {
                    LSC[i] = max(LSC[i], 1+LSC[j]);
                }
            }
            maxLen = max(maxLen, LSC[i]);
        }

        return maxLen;
    }
};