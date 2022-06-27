class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string say = countAndSay(n - 1);
        int len = say.length();
        
        string ret;
        for(int i = 0; i < len; i++){
            int count = 1;
            while(i + 1 < len and say[i + 1] == say[i])
                i += 1, count += 1;
            ret += to_string(count) + say[i];
        }
        
        return ret;
    }
};