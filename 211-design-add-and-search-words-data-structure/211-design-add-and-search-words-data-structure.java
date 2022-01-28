class TrieNode{
    boolean ending;
    TrieNode[] children;
    TrieNode(){
        ending = false;
        children = new TrieNode[26];
    }
}
class WordDictionary {
    TrieNode root;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode curr = root;
        for(int i=0; i<word.length(); i++){
            int index = word.charAt(i) - 'a';
            if(curr.children[index] == null)
                curr.children[index] = new TrieNode();
            curr = curr.children[index];
        }
        curr.ending = true;
    }
    
    public boolean search(String word) {
        return search(word.toCharArray(), 0, root);
    }
    
    boolean search(char[] word, int k, TrieNode node){
        if(k == word.length)
            return node.ending == true;
        if(word[k] == '.'){
            for(int i=0; i<26; i++){
                if(node.children[i] != null){
                    if(search(word, k+1, node.children[i]))
                        return true;
                }
            }
            return false;
        }
        return node.children[word[k]-'a'] != null && search(word, k+1, node.children[word[k]-'a']);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */