class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        int len = s.length();
        
        for(int i = 0; i < len; i++){
            int idx = s[i] - 'a';
            last[idx] = i;
        }
        
        vector<int> ans;
        ans.reserve(len / 2);
        
        for(int i = 0; i < len; i++){
            int start = i;
            int end = last[s[i] - 'a'];
            while(i < end){
                int idx = s[i] - 'a';
                if(last[idx] > end)
                    end = last[idx];
                i++;
            }
            ans.push_back(end - start + 1);
        }
        
        return ans;
    }
};