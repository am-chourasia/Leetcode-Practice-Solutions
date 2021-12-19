class Solution {
public:
    string decodeString(string s) {
        return decode(s, 0, s.size());
    }
    string decode(string& s, int start, int end){
        string ans;
        int left, right, i = start;
        while(i < end){
            if(isdigit(s[i])){
                int times = 0;
                while(isdigit(s[i])){
                    times = times * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                left = i;
                int b = 1; // brackets
                while(b != 0){
                    if(s[i] == ']')
                        b--;
                    else if(s[i] == '[')
                        b++;
                    i++;
                }
                right = i - 1;
                string temp = decode(s, left, right);
                while(times--)
                    ans.append(temp);
            }
            else
                ans.push_back(s[i++]);
        }
        return ans;
    }
};