class Solution {
    int to_number(string& digits, int start, int end){
        int ans = 0;
        for(int i = start; i <= end; i++)
            ans = ans * 10 + (digits[i] - '0');
        return ans;
    }
public:
    vector<int> sequentialDigits(const int low,const int high) {
        string digits = "123456789";
        vector<int> ans;
        bool shouldStop = false;
        int lowLength = log10(low) + 1;
        int highLength = log10(high) + 1;
        
        for(int windowLength = lowLength; windowLength <= highLength; windowLength++){
            for(int start = 0, end = windowLength-1; end < 9; start++, end++){
                int num = to_number(digits, start, end);
                if(num >= low and num <= high)
                    ans.push_back(num);
                else if(num > high){
                    shouldStop = true;
                    break;
                }
            }
            if(shouldStop)
                break;
        }
        
        return ans;
    }
};