class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        stack<int> openings;
        int inserts = 0;
        
        for(int i = 0; i < len; i++){
            if(s[i] == '('){
                openings.push(i);
            } else if(s[i] == ')'){
                if(i + 1 < len and s[i + 1] == ')'){
                    if(not openings.empty())
                        openings.pop();
                    else 
                        inserts += 1;
                    s[i + 1] = '#';
                } else {
                    inserts += 1;
                    if(not openings.empty())
                        openings.pop();
                    else 
                        inserts += 1;
                }
            }
        }
        inserts += openings.size() * 2;
        
        return inserts;
    }
};