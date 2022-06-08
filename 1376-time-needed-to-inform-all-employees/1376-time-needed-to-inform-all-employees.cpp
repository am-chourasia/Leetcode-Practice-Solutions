class Solution {
    int findReachTime(int i, vector<int>& parent, vector<int>& informTime, vector<int>& reachTime){
        if(reachTime[i] < 0)
            reachTime[i] = findReachTime(parent[i], parent, informTime, reachTime);
        return reachTime[i] + informTime[i];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> reachTime(n, -1);
        reachTime[headID] = 0;
        
        for(int i = 0; i < n; i++){
            if(reachTime[i] < 0)
                findReachTime(i, manager, informTime, reachTime);
        }
        
        return * max_element(reachTime.begin(), reachTime.end());
    }
};