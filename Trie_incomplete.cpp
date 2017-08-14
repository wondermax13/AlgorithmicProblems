
class TrieNode {
    
public:    
    char c;
    set<TrieNode> nextChars;
    bool isWord;
        
    TrieNode(char c_) { //: c(c_) : isWord(false) {
            
        c = c_;
        isWord = false;
    }
        
    TrieNode() {
            
        isWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        if(word.size() > 0) {
            
            head = new TrieNode(word[0]);
            
            TrieNode p = head;
            for(int index = 1; index < word.size(); index++) {
                
                p
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        return true;
    }
    
    TrieNode head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */