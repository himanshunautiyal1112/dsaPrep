class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> st;

        for(char str: s) {
            st[str]++;
        }

        for(char str: t) {
            st[str]--;
        }

        for(auto p: st) {
            if(p.second!=0)
            return false;
        }

        return true;
    }
};