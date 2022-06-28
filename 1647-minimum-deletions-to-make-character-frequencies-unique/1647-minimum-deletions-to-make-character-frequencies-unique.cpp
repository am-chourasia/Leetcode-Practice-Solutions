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
            if(allowed == 0){
                deleteCount += count;
            } else if (count > allowed) {
                deleteCount += count - allowed;
                allowed--;
            } else {
                allowed = count - 1;
            }
        }
        
        return deleteCount;
    }
};