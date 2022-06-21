class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int length = heights.size();
        priority_queue<int> largestJumps;
        int bricksUsed = 0;
        int laddersRemaining = ladders;
        
        int building = 0;
        for(building = 0; building < length - 1; building++){
            int jump = max(0, heights[building + 1] - heights[building]);
            largestJumps.push(jump);
            bricksUsed += jump;
            if(bricksUsed > bricks){
                if(laddersRemaining == 0)
                    break;
                laddersRemaining -= 1;
                bricksUsed -= largestJumps.top();
                largestJumps.pop();
            }
        }
        
        return building;
    }
};