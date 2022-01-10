class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        string ans;
        int i = n-1, j = m-1;
        int carry = 0;
        
        while(i >= 0 and j >= 0){
            if(a[i] == '1' and b[j] == '1'){
                if(carry == 1)
                    ans.push_back('1');
                else
                    ans.push_back('0'), carry = 1;
            } else if(a[i] == '1' or b[j] == '1'){
                if(carry == 1)
                    ans.push_back('0');
                else
                    ans.push_back('1');
            } else {
                if(carry == 1)
                    ans.push_back('1'), carry = 0;
                else
                    ans.push_back('0');
            }
            i--, j--;
        }
        while(i >= 0){
            if(a[i] == '1' and carry == 1)
                ans.push_back('0');
            else if(a[i] == '1' or carry == 1)
                ans.push_back('1'), carry = 0;
            else
                ans.push_back('0');
            i--;
        }
        while(j >= 0){
            if(b[j] == '1' and carry == 1)
                ans.push_back('0');
            else if(b[j] == '1' or carry == 1)
                ans.push_back('1'), carry = 0;
            else
                ans.push_back('0');
            j--;
        }
        if(carry == 1)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};