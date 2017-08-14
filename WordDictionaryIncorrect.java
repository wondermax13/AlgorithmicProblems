public class WordDictionary {

    /** Initialize your data structure here. */
    public WordDictionary() {
        
        set = new HashSet<String>();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        
        if(!set.contains(word)) {
            
            set.add(word);
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        
        boolean found = false;
        Iterator<String> iter = set.iterator();
        
        while(iter.hasNext() && !found) {
            
            String entry = (String)iter.next();
            
            found = doWordsMatch(entry, word);
        }
        
        return found;
    }
    
    protected boolean doWordsMatch(String entry, String word) {
        
        boolean mismatchFound = false;
        if(entry.length() != word.length()) {
            
            mismatchFound = true;
        }
        else {
            
            int index = 0;
            while(index < entry.length() && !mismatchFound) {
                
                mismatchFound 
                    = !(word.charAt(index) == '.' 
                        || word.charAt(index) == entry.charAt(index));
                ++index;
            }
        }
        
        return !mismatchFound;
    }
    
    protected int firstAlphabetInstance(String word) {
        
        int alphaIndex = 0;
        boolean found = false;
        
        while(alphaIndex < word.length() && !found) {
            
            found = (word.charAt(alphaIndex) != '.');
            
            ++alphaIndex;
        }
        
        return alphaIndex;
    }
    
    protected Set<String> set;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */