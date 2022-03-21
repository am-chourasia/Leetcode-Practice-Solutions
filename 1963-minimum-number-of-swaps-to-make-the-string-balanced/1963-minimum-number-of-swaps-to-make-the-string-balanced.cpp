class Solution {
public:
    int minSwaps(string s) {
        stack<int> openings;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == '[')
                openings.push(i);
        }
        
        int open = 0;
        int swaps = 0;
        
        for(int i = 0; i < len; i++){
            if(s[i] == '[')
                open++;
            else if(open <= 0){
                int idx = openings.top();
                openings.pop();
                swap(s[i], s[idx]);
                swaps++;
                open++;
            } else 
                open--;
        }
        
        return swaps;
    }
};