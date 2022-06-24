class Solution {
    int ceilDivision(int x, int y){
        // ans = ceil(x / y)
        //     = (x + 1 + y) / y;
        return 1 + (x - 1) / y;
    }
public:
    bool isPossible(std::vector<int>& target) {
        int len = target.size();
        if(len == 1)
            return target[0] == 1;
        
        std::priority_queue<int> maxHeap;
        long runningSum = 0;
        for(int element : target){
            runningSum += element;
            maxHeap.push(element);
        }
        
        while(true){
            int maxElement = maxHeap.top(); maxHeap.pop();
            int secondMax = maxHeap.top();
            if(maxElement == 1)
                return true;
            runningSum -= maxElement;
            if(maxElement <= runningSum)
                return false;
            int factor = ceilDivision(maxElement - secondMax, runningSum);
            int required = maxElement - runningSum * factor;
            if(required <= 0)
                return false;
            runningSum += required;
            maxHeap.push(required);
        }
        
        return false;
    }
};