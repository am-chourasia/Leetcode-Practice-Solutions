class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        var set = new HashSet<String>();
        for(int i = 0; i < wordList.size(); i++)
            set.add(wordList.get(i));
        set.remove(beginWord);
        if(!set.contains(endWord)) 
            return 0;
        
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        int changes = 1;
        
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int __ = 0; __ < size; __++){
                String word = queue.poll();
                if(word.equals(endWord))
                    return changes;
                var str = new StringBuilder(word);
                for(int j = 0; j < word.length(); j++){
                    char original = word.charAt(j);
                    for(char k = 'a'; k <= 'z'; k++){
                        str.setCharAt(j, k);
                        String converted = str.toString();
                        if(set.contains(converted)){
                            queue.add(converted);
                            set.remove(converted);
                        }
                    }
                    str.setCharAt(j, original);
                }
            }
            ++changes;
        }
        
        return 0;
    }
}