class Solution {
public:
    std::string removeDuplicateLetters(std::string& s) {
        std::unordered_map<char, int> freq;
        for(char& c : s)
            freq[c]++;
        std::stack<int> stack;
        std::unordered_set<char> visited;
        
        for(char& c : s){
            freq[c]--;
            if(not visited.count(c)){
                while(not stack.empty() and stack.top() > c and freq[stack.top()] > 0 ){
                    visited.erase(stack.top());
                    stack.pop();
                }
                stack.push(c);
                visited.insert(c);
            }
        }
        
        string ans;
        ans.reserve(stack.size());
        while(not stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};