class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<int> visited(numCourses, false);
        vector<vector<int>> graph(numCourses);
        vector<int> finishedCourses;
            
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
        
        while(!queue.empty()){
            int course = queue.front(); queue.pop();
            visited[course] = true;     // mark this course as done
            finishedCourses.push_back(course); // push the course into the finished one
            for(int dependent : graph[course]){
                degree[dependent]--;
                if(degree[dependent] == 0)
                    queue.push(dependent);
            }
        }
        
        for(int i = 0; i < numCourses; i++)
            if(visited[i] == false)
                return vector<int>();
        
        return finishedCourses;
    }
};