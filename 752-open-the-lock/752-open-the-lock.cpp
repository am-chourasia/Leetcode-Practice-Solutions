class Solution {
    char moveForward(char digit){
        if(digit == '9')
            return '0';
        return ++digit;
    }
    char moveBackward(char digit){
        if(digit == '0')
            return '9';
        return --digit;
    }
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::unordered_set<std::string> begin;
        std::unordered_set<std::string> end;
        std::unordered_set<std::string> deads(deadends.begin(), deadends.end());
        if(deads.find("0000") != deads.end())
            return -1;
                                                                          
        begin.insert("0000");
        end.insert(target);
        
        // bidirectional search
        int steps = 0;
        
        while(begin.size() > 0 and end.size() > 0){
            std::unordered_set<std::string> nextStates;
            for(const string& lock : begin){
                if(end.find(lock) != end.end()) // if the two sets intersect at any point
                    return steps;
                deads.insert(lock);
                for(int i = 0; i < 4; i++){
                    std::string forward = lock.substr(0, i) + moveForward(lock[i]) + lock.substr(i + 1);
                    std::string backward = lock.substr(0, i) + moveBackward(lock[i]) + lock.substr(i + 1);
                    if(deads.find(forward) == deads.end())
                        nextStates.insert(forward);
                    if(deads.find(backward) == deads.end())
                        nextStates.insert(backward);
                }
            }
            begin = end;
            end = nextStates;
            steps++;
        }
        
        return -1;
    }
};