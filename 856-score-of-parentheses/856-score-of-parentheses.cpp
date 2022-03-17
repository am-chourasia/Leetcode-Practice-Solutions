class Solution {
public:
    int scoreOfParentheses(string& s){
        return helper(s, 0, s.length() - 1);
    }
    int helper(string& s, int start, int end) {
        int n = end - start + 1;
        if(end <= start)
            return 0;
        if(n == 2)
            return 1;
        
        int balance = 0;
        int i = start;
        
        while(i <= end){
            if(s[i] == '(')
                balance++;
            else
                balance--;
            if(balance == 0)
                break;
            i++;
        }

        int self = (i == start + 1) ? 1 : 0;
        int inside = 2 * helper(s, start + 1, i - 1);
        int side = helper(s, i + 1, end);
        return self + inside + side;
    }
};