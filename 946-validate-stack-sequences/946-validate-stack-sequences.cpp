class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        unordered_set<int> inserted;
        std::stack<int> stack;
        int n = pushed.size();
        int i = 0, j = 0;
        
        while(i < n){
            stack.push(pushed[i]);
            inserted.insert(pushed[i]);
            i++;
            if(stack.top() == popped[j])
                break;
        }
        
        while(j < n){
            if(not stack.empty() and popped[j] == stack.top()){
                stack.pop();
                j++;
            } else if(inserted.count(popped[j])){
                return false;
            } else {
                while(pushed[i] != popped[j]){
                    stack.push(pushed[i]);
                    inserted.insert(pushed[i]);
                    i++;
                }
                i++;
                j++;
            }
        }
        return true;
    }
};