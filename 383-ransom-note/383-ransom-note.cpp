class Solution {
public:
    bool canConstruct(const string& ransomNote, const string& magazine) {
        unordered_map<char, int> freq;
        for (char c : magazine)
            freq[c] += 1;
        for (char c : ransomNote) 
            freq[c] -= 1;
        for (auto& [elem, count] : freq)
            if (count < 0)
                return false;
        return true;
    }
};