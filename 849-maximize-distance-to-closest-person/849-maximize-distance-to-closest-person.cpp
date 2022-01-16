class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        vector<int> distance(len);
        int ans = 0;
        
        // calculating empty seat distance from leftmost occupied seat;
        int left = -100000;
        for(int i = 0; i < len; i++){
            if(seats[i] == 1){
                left = i;
            } else {
                distance[i] = i - left;
            }
        }
        
        // calculating empty seat distance from rightmost occupied seat
        // and taking the minimum of this with the left value
        int right = 100000;
        for(int i = len-1; i >= 0; i--){
            if(seats[i] == 1){
                right = i;
            } else {
                distance[i] = min(distance[i], right - i);
                ans = max(distance[i], ans);
            }
        }
        
        return ans;
    }
};