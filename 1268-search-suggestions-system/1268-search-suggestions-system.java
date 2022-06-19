class TrieNode{
    public boolean ending;
    public TrieNode[] children;
    public int[] indexes;
    public TrieNode(){
        ending = false;
        children = new TrieNode[26];
        indexes = new int[3];
        Arrays.fill(indexes, -1);
    }
    public void addWordIndex(int index){
        for(int i = 0; i < 3; i++){
            if(indexes[i] < 0){
                indexes[i] = index;
                break;
            }
        }
    }
    public void addSuggestions(List<String> suggestions, String[] products){
        for(int i = 0; i < 3; i++){
            if(indexes[i] >= 0){
                int idx = indexes[i];
                suggestions.add(products[idx]);
            }
        }
    }
}

class Trie {
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    public void insert(String word, int index) {
        TrieNode curr = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word.charAt(i) - 'a';
            if(curr.children[idx] == null)
                curr.children[idx] = new TrieNode();
            curr = curr.children[idx];
            curr.addWordIndex(index);
        }
        curr.ending = true;
    }
    public List<List<String>> findSuggestions(String search, String[] products){
        List<List<String>> suggestions = new ArrayList<List<String>>();
        for(int i = 0; i < search.length(); i++)
            suggestions.add(new ArrayList<String>());
        
        TrieNode current = root;
        for(int i = 0; i < search.length(); i++){
            int idx = search.charAt(i) - 'a';
            current = current.children[idx];
            if(current == null)
                break;
            current.addSuggestions(suggestions.get(i), products);
        }
        return suggestions;
    }
}
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        Trie trie = new Trie();
        for(int i = 0; i < products.length; i++)
            trie.insert(products[i], i);
        
        return trie.findSuggestions(searchWord, products);
    }
}