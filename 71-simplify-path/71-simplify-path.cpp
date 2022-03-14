class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        stack<string> reversedCanonical;
        string dir;
        
        while(getline(ss, dir, '/')){
            if(not dir.empty()){
                if(dir == ".."){
                    if(not reversedCanonical.empty())
                        reversedCanonical.pop();
                }
                else if(dir != "."){
                    reversedCanonical.push(dir);
                }
            }
        }
        
        stack<string> canonical;
        int size = 0;
        while(not reversedCanonical.empty()){
            canonical.push(reversedCanonical.top());
            size += reversedCanonical.top().size();
            reversedCanonical.pop();
        }
        
        string ans = "/";
        ans.reserve(size);
        
        while(not canonical.empty()){
            ans.append(canonical.top());
            ans.push_back('/');
            canonical.pop();
        }
        if(ans != "/")
            ans.pop_back();
        
        return ans;
    }
};