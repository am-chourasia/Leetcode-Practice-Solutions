class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (string& word : words) 
            freq[word] += 1;
        
        int palLength = 0;
        bool doublePossible = false;
        
        for (string& word : words) {
            if (freq[word] > 0) {       
                // means it was not paired
                string reversedWord(word);
                reverse(reversedWord.begin(), reversedWord.end());
                if (reversedWord == word) {
                    palLength += (freq[word]/ 2) * 4;
                    doublePossible |= ((freq[word] % 2) == 1);
                    freq[word] = 0;
                } else if (freq[reversedWord] > 0) {
                    // pair it with the current word
                    freq[word] -= 1;    
                    freq[reversedWord] -= 1;
                    palLength += 4;     
                }
            }
        }
        
        if (doublePossible)
            palLength += 2;
        
        return palLength;
    }
};