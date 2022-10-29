class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> A(n);
        for(int i = 0; i < n; i++){
            A[i] = {growTime[i], plantTime[i]};
        }
        sort(A.begin(), A.end(), greater<pair<int,int>>());
        
        int days = 0, start = 0;
        for(int i = 0; i<n; i++){
            start = start + A[i].second;
            int newCompletion = start + A[i].first;
            days = max(days, newCompletion);
        }
        
        return days;
    }
};