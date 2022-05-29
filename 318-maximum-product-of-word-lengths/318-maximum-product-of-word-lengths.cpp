class Solution {
    void setBit(int& val, int b){
        int mask = 1 << b;
        val = val | mask;
    }
    int hash(string& word){
        int val = 0;
        for(char c : word)
            setBit(val, c - 'a');
        return val;
    }
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> hashes(n);
        
        for(int i = 0; i < n; i++)
            hashes[i] = hash(words[i]);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((hashes[i] & hashes[j]) == 0){
                    int val = words[i].length() * words[j].length();
                    ans = max(ans, val);
                }
            }
        }
        
        return ans;
    }
};