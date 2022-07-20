class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        array<vector<int>, 26> indexes;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int letter = s[i] - 'a';
            indexes[letter].push_back(i);
        }
        
        int count = 0;
        for (string& word : words) {
            int index = -1;
            bool allCharFound = true;
            for(char elem : word){
                auto& arrayToSearch = indexes[elem - 'a'];
                auto it = upper_bound(arrayToSearch.begin(), arrayToSearch.end(), index);
                if(it == arrayToSearch.end()){
                    allCharFound = false;
                    break;
                }
                index = *it;
            }
            if(allCharFound)
                count += 1;
        }
        
        return count;
    }
};