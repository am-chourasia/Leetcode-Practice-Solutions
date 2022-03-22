class Solution {
public:
    std::vector<int> findOriginalArray(std::vector<int>& changed) {
        int len = changed.size();
        if(len % 2 == 1)
            return std::vector<int>();
        
        multiset<int> elements(changed.begin(), changed.end());
            
        std::vector<int> original;
        original.reserve(len / 2);
        
        for(auto it = elements.rbegin(); it != elements.rend(); it++){
            int element = *it;
            if(element % 2 == 1)
                return std::vector<int>();
            if(elements.find(element / 2) != elements.end()){
                elements.erase(elements.lower_bound(element / 2));
                original.push_back(element / 2);
            }
            else 
                return std::vector<int>();
        }
        return original;
    }
};