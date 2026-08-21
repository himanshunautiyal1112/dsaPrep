class Solution {
public:
    bool checkPref(string &word, string &pref) {
        int i = 0;
        int n = pref.size();

        while(i<n) {
            if(pref[i] != word[i])
            return false;

            i++;
        }

        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(int i=0; i<words.size(); i++) {
            if(checkPref(words[i], pref)) {
                ans++;
            }
        }
        return ans;
    }
};