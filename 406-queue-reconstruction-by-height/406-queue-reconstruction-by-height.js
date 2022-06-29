class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0])
                return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int len = people.size();
        vector<vector<int>> queue;
        queue.reserve(len);
        int index = -1;
        
        for(vector<int>& person : people){
            int frontCount = person[1];
            queue.insert(queue.begin() + frontCount, person);
        }
        
        return queue;
    }
};