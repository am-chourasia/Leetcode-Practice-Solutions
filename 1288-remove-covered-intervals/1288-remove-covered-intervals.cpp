class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& interval1, const vector<int>& interval2){
            if(interval1[0] == interval2[0])
                return interval1[1] > interval2[1];
            return interval1[0] < interval2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 1;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& interval = intervals[i];
            if(not (interval[0] >= start and interval[1] <= end)){
                start = interval[0];
                end = interval[1];
                ans++;
            }
        }
        return ans;
    }
};