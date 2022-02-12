class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, Boolean> map = new HashMap<>();
        for(int i = 0; i < wordList.size(); i++)
            map.put(wordList.get(i), false);
        
        if(!map.containsKey(endWord)) 
            return 0;
        
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        
        int changes = 1;
        
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0; i < size; i++){
                String word = queue.poll();
                if(word.equals(endWord)) 
                    return changes;

                for(int j = 0; j < word.length(); j++){
                    for(char k = 'a'; k <= 'z'; k++){
                        char arr[] = word.toCharArray();
                        arr[j] = k;

                        String str = new String(arr);
                        if(map.containsKey(str) && !map.get(str)){
                            queue.add(str);
                            map.put(str, true);
                        }
                    }
                }   
            }
            ++changes;
        }
        return 0;
    }
}