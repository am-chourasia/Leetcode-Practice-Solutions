class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<int> visited(numCourses, false);
        vector<vector<int>> graph(numCourses);
        
        for(vector<int>& require : prerequisites){
            int course = require[0];
            int preCourse = require[1];
            graph[preCourse].push_back(course);
            degree[course] ++ ;
        }
        
        std::queue<int> queue;  // will store the independent courses at any moment
        for(int i = 0; i < numCourses; i++){
            int deg = degree[i];
            if(deg == 0)        // if the current course is independent, push into queue
                queue.push(i);
        }
        
        int count = 0;
        
        while(!queue.empty()){
            int course = queue.front(); queue.pop();
            count++;
            visited[course] = true;     // mark this course as done
            for(int dependent : graph[course]){
                degree[dependent]--;
                if(degree[dependent] == 0)
                    queue.push(dependent);
            }
        }
        
        if(count < numCourses)
            return false;
        
        return true;
    }
};