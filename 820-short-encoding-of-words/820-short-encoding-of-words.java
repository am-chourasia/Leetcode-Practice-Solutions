class TrieNode{
    boolean isEnding;
    Map<Character, TrieNode> children;
    TrieNode(){
        children = new HashMap<>();
        isEnding = false;
    }
}
class Trie{
    TrieNode root;
    int length;
    Trie(){
        root = new TrieNode();
        length = 0;
    }
    void insert(String word){
        TrieNode current = root;
        for(int i = word.length() - 1; i >= 0; i--){
            char character = word.charAt(i);
            if(!current.children.containsKey(character))
                current.children.put(character, new TrieNode());
            current = current.children.get(character);
        }
        current.isEnding = true;
    }
    int countNodes(TrieNode node){
        if(node.children.size() == 0){
            length += 1;
            return 1;
        }
        int len = 0;
        for(var entry: node.children.entrySet())
            len += countNodes(entry.getValue());
        length += len;
        return len;
    }
    int shortestRefLength(){
        length = 0;
        countNodes(root);
        return length;
    }
}
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Trie trie = new Trie();
        for(String word : words)
            trie.insert(word);
        return trie.shortestRefLength();
    }
}