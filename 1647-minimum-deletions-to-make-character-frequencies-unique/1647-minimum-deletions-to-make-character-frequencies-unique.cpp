class Solution {
public:
    int minDeletions(string s) {
        map<char, int> freq;
        for(char element : s)
            freq[element]++;
        
        std::priority_queue<int> maxHeap;
        for (auto& [element, count] : freq) 
            maxHeap.push(count);
        
        int allowed = 1'000'000;
        int deleteCount = 0;
        while(not maxHeap.empty()){
            int count = maxHeap.top();
            maxHeap.pop();
            if (count > allowed) {
                deleteCount += count - allowed;
                count = allowed;   
            }
            allowed = max(0, count - 1);
        }
        
        return deleteCount;
    }
};