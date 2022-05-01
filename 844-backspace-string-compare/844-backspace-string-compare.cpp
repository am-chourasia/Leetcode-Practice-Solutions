class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        int i = n1 - 1, j = n2 - 1;
        
        while(true){
            int countHash = 0;
            while(i>=0){
                if(s[i] == '#')
                    countHash++, i--;
                else if(countHash > 0)
                    countHash--, i--;
                else
                    break;
            }
            countHash = 0;
            while(j>=0){
                if(t[j] == '#')
                    countHash++, j--;
                else if(countHash > 0)
                    countHash--, j--;
                else
                    break;
            }
            if(j<0 || i<0)
                break;
            if(s[i] != t[j])
                return false;
            i--; j--;
        }
        return (i<0 && j<0);
    }
};