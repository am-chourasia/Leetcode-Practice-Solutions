class Solution {
public:
    int brokenCalc(int start, int target) {
        if(start == target)
            return 0;
        if(start > target)
            return start - target;
        
        if(start * 2 > target){
            target = (target % 2) ? target - 1 : target;
            int minus = start - target / 2;
            return minus + 1;
        }
        
        int count = 0;
        while(true){
            int current = start;
            int doubles = 0;
            while(current < target){
                current <<= 1;
                doubles++;
            }
            
            int diff = current - target;
            if(diff == 0){
                count += doubles;
                break;
            }
            
            int backsteps = log2(diff);
            int double_steps = doubles - backsteps;
            
            if(double_steps < 0){
                double_steps = -double_steps;
                start = start - (1 << double_steps);
                count += (1 << double_steps);
            } else {
                start = (start << double_steps) - 1;
                count += double_steps + 1;
            }
        }
        
        return count;
    }
};