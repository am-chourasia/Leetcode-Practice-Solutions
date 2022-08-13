class Solution {
    map<string, int> wordsCount;
    bool isValid(string& substring, int wordLength){
        int len = substring.length();
        map<string, int> seen;
        for(int i = 0; i < len; i += wordLength){
            string word = substring.substr(i, wordLength);
            seen[word] += 1;
            if(wordsCount.find(word) == wordsCount.end() or seen[word] > wordsCount[word])
                return false;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        for(string& word : words)
            wordsCount[word]++;
        
        int totalWords = words.size();
        int wordLength = words[0].size();
        int totalWordsLength = totalWords * wordLength;
        int len = s.length();
        
        vector<int> indexes;
        for(int i = 0; i < len - totalWordsLength + 1; i++){
            string substring = s.substr(i, totalWordsLength);
            if(isValid(substring, wordLength))
                indexes.push_back(i);
        }
        return indexes;
    }
};