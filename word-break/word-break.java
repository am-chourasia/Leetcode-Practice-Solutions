class Solution {
    class TrieNode{
        boolean end;
        TrieNode[] children;
        TrieNode(){
            end = false;
            children = new TrieNode[26];
            for(int i=0; i<26; i++)
                children[i] = null;
        }
        TrieNode nextNode(char child){
            int index = child - 'a';
            return (children[index] != null) ? children[index] : null;
        }
    }
    class Trie{
        TrieNode root;
        Trie(){
            root = new TrieNode();
        }
        void insert(String key){
            TrieNode curr = root;
            for(int i=0; i<key.length(); i++){
                int c = key.charAt(i) - 'a';
                if(curr.children[c] == null)
                    curr.children[c] = new TrieNode();
                curr = curr.children[c];
            }
            curr.end = true;
        }
    }
    String searchString;
    int util(int start, TrieNode root, int[] dp){
        if(start >= searchString.length())
            return 1;
        if(dp[start] != -1)
            return dp[start];
        TrieNode node = root;
        for(int i = start; i<searchString.length(); i++){
            node = node.nextNode(searchString.charAt(i));
            if(node == null)
                return dp[start] = 0;
            else if(node.end == true && util(i+1, root, dp) == 1)
                    return dp[start] = 1;
        }
        return dp[start] = 0;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        Trie head = new Trie();
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        searchString = s;
        
        for(int i=0; i<wordDict.size(); i++)
            head.insert(wordDict.get(i));
        
        return util(0, head.root, dp) == 1;
    }
}