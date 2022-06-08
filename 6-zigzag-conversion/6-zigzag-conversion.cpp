class Solution {
public:
    string convert(string s, int numRows) {
        int idx = 0;
        int len = s.length();
        
        if(numRows == 1)
            return s;
        
        string zigzag;
        zigzag.reserve(len);
        
        int add1 = 2 * numRows - 2;
        int add2 = 0;
        
        for(int i = 0; i < numRows; i++){
            idx = i;
            int parity = 0;
            
            while(idx < len){
                zigzag.push_back(s[idx]);
                parity = parity ^ 1;
                if(add1 == 0 or add2 == 0)
                    idx += add1 + add2;
                else if(parity == 1)
                    idx += add1;
                else
                    idx += add2;
            }
            
            add1 -= 2;
            add2 += 2;
        }
        
        return zigzag;
    }
};