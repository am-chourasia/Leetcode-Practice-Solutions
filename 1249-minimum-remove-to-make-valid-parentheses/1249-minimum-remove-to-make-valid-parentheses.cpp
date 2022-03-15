class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        unordered_set<int> indexes;
        stack<int> openings;
        
        for(int idx = 0; idx < len; idx++) {
            if(s[idx] == ')'){
                if(openings.empty()){
                    indexes.insert(idx);
                } else {
                    int last = openings.top();
                    indexes.erase(last);
                    openings.pop();
                }
            } else if(s[idx] == '(') {
                openings.push(idx);
            }
        }
        
        while(not openings.empty()) {
            int idx = openings.top();
            indexes.insert(idx);
            openings.pop();
        }
        
        string ans;
        ans.reserve(len - indexes.size());
        
        for(int i = 0; i < len; i++) {
            if(not indexes.count(i))
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};