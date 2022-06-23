class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int len = courses.size();
        sort(courses.begin(), courses.end(), [&](const vector<int>& a, const vector<int>& b){
            if(a[1] != b[1])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        priority_queue<int> pq; 
        int count = 0, time = 0;
        
        for(int i = 0; i < len; i++){
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            if(time + duration <= lastDay){
                count++;
                time += duration;
                pq.push(duration);
            } else if(pq.size() > 0){
                int maxDuration = pq.top();
                if(maxDuration > duration){ // remove the maxDuration course
                    pq.pop();
                    time = time - maxDuration + duration;
                    pq.push(duration);
                }
            }
        }
        
        return count;
    }
};