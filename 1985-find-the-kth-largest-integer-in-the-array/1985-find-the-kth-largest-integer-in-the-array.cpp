class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto compare = [&](const string &a,const string &b) {
            int n = a.length();
            int m = b.length();
            if(n > m)
                return true;
            if(m > n)
                return false;
            for(int i = 0; i < n; i++)
                if(a[i] > b[i])
                    return true;
                else if(b[i] > a[i])
                    return false;
            return false;
        };
        priority_queue<string, vector<string>, decltype(compare)> pq(compare);
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
            cout << pq.top() << " ";
        }
        cout << endl;
        return pq.top();
    }
};