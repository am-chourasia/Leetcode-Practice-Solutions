class Solution {
    private char scrollForward(char digit){
        if(digit == '9')
            return '0';
        return ++digit;
    }
    private char scrollBackward(char digit){
        if(digit == '0')
            return '9';
        return --digit;
    }
    public int openLock(String[] deadends, String target) {
        var deads = new HashSet<String>(Arrays.asList(deadends));
        if(deads.contains("0000"))
            return -1;
        var begin = new HashSet<String>();
        var end = new HashSet<String>();
        int steps = 0;
            
        begin.add("0000");
        end.add(target);
        
        while(!begin.isEmpty() && !end.isEmpty()){
            if(begin.size() > end.size()){
                var temp = begin;
                begin = end;
                end = temp;
            }
            var nextStates = new HashSet<String>();
            for(String lock : begin){
                if(end.contains(lock))
                    return steps;
                deads.add(lock);
                StringBuilder builder = new StringBuilder(lock);
                for(int i = 0; i < 4; i++){
                    String forward = builder.substring(0, i) + scrollForward(lock.charAt(i)) + builder.substring(i + 1);
                    String backward = builder.substring(0, i) + scrollBackward(lock.charAt(i)) + builder.substring(i + 1);
                    if(!deads.contains(forward))
                        nextStates.add(forward);
                    if(!deads.contains(backward))
                        nextStates.add(backward);
                }
            }
            begin = nextStates;
            steps++;
        }
        
        return -1;
    }
}