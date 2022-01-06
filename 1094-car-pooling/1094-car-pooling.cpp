class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int course[1001] = {0};
        for(vector<int>& trip : trips){
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            course[start] += passengers;
            course[end] -= passengers;
        }
        int passengers = 0;
        for(int i = 0; i < 1001; i++){
            passengers += course[i];
            if(passengers > capacity)
                return false;
        }
        return true;
    }
};