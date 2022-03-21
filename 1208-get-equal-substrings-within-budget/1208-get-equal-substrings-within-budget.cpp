class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length();
        vector<int> diff(len);
        for(int i = 0; i < len; i++)
            diff[i] = abs(s[i] - t[i]);
        
        int sum = diff[0];
        int largest_subarray = sum <= maxCost ? 1 : 0;
        int p1 = 0, p2 = 1;
        
        while(p2 < len){
            sum += diff[p2];
            while(sum > maxCost and p1 <= p2){
                sum -= diff[p1];
                p1++;
            }
            largest_subarray = max(largest_subarray, p2 - p1 + 1);
            p2++;
        }
        
        return largest_subarray;
    }
};