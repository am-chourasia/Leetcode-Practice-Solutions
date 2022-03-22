class Solution {
public:
    std::vector<int> findOriginalArray(std::vector<int>& changed) {
        int len = changed.size();
        if(len % 2 == 1)
            return std::vector<int>();
        
        multiset<int> elements(changed.begin(), changed.end());
        int zeroes = 0;
        for(const int& ele : elements){
            if(ele == 0)
                zeroes++;
            else
                break;
        }
        if(zeroes % 2 == 1)
            return std::vector<int>();
            
        std::vector<int> original;
        original.reserve(len / 2);
        
        for(auto it = elements.rbegin(); it != elements.rend(); it++){
            int element = *it;
            if(element == 0)
                break;
            if(element % 2 == 1)
                return std::vector<int>();
            if(elements.count(element / 2)){
                elements.erase(elements.lower_bound(element / 2));
                original.push_back(element / 2);
            }
            else 
                return std::vector<int>();
        }
        for(int i = 0; i < zeroes/2; i++)
            original.push_back(0);
        return original;
    }
};