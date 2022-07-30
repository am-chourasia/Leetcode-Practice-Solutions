class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> maxFreq;
        for(string& word : words2){
            map<char, int> freq;
            for(char c : word)
                freq[c]++;
            for(auto& [character, count] : freq)
                maxFreq[character] = max(maxFreq[character], count);
        }
        
        vector<string> ans;
        
        for(string& word : words1){
            map<char, int> freq;
            for(char c : word)
                freq[c]++;
            bool isGood = true;
            for(auto& [character, count] : maxFreq){
                if(freq[character] < count){
                    isGood = false;
                    break;
                }
            }
            if(isGood)
                ans.push_back(word);
        }
        
        return ans;
    }
};