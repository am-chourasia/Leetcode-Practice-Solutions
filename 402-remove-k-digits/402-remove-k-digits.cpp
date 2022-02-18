class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        if(k == len)
            return "0";
        
        string stack;
        stack.reserve(len - k);
        
        for(char digit : num){
            while(not stack.empty() and stack.back() > digit and k > 0)
                stack.pop_back(), k--;
            stack.push_back(digit);
        }
        
        // removing extra elements if possible
        while(k > 0)
            stack.pop_back(), k--;
        
        // trimming trailing zeroes
        int start = 0;
        while(start < stack.size() and stack[start] == '0')
            start++;
        if(start == stack.size())
            return "0";
        
        return stack.substr(start);
    }
};