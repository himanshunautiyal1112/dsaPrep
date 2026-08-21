class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd;
    
        TrieNode() {
            isEnd = false;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
        }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(char ch: word) {
            int index = ch - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool dfs(string &word, int pos, TrieNode* curr) {
        if(curr == NULL) return false;

        if(pos == word.size())
        return curr->isEnd;

        if(word[pos] == '.') {
            for(int i=0; i<26; i++) {
                if(dfs(word, pos+1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        }
        int index = word[pos] - 'a';
        return dfs(word, pos+1, curr->children[index]);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */