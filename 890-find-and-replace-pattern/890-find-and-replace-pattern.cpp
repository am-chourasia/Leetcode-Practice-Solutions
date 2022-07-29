class Solution {
    string normalise(string& original){
        string normalisedString = "";
        map<char, char> mapping;
        char nextChar = 'a';
        for(char c : original){
            if(mapping.find(c) == mapping.end())
                mapping[c] = nextChar++;
            normalisedString.push_back(mapping[c]);
        }
        return normalisedString;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string normalisedPattern = normalise(pattern);
        vector<string> ans; 
        for(string& word : words){
            if(normalise(word) == normalisedPattern)
                ans.push_back(word);
        }
        return ans;
    }
};