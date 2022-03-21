class Solution {
public:
    int minAddToMakeValid(string s) {
        int inserts = 0;
        int mismatch = 0;
        int openings = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                openings++;
            else if(openings > 0)
                openings--;
            else 
                mismatch++;
        }
        mismatch += openings;
        
        return abs(mismatch);
    }
};