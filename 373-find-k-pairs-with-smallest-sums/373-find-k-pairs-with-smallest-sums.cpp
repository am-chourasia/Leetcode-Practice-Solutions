class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        struct Tuple{
            int i;
            int j;
            int nums_i;
            int nums_j;
            Tuple(int i, int j, int nums_i, int nums_j){
                this->i = i;
                this->j = j;
                this->nums_i = nums_i;
                this->nums_j = nums_j;
            }
        };
        struct Compare{
            bool operator()(const Tuple& t1, const Tuple& t2){
                int sum1 = t1.nums_i + t1.nums_j;
                int sum2 = t2.nums_i + t2.nums_j;
                if(sum1 < sum2)
                    return false;
                return true;
            }
        };
        priority_queue<Tuple, vector<Tuple>, Compare> pq;
        
        for(int i = 0; i < n1; i++){
            Tuple t(i, 0, nums1[i], nums2[0]);
            pq.push(t);
        }
        
        vector<vector<int>> ans;
        ans.reserve(k);
        
        while(k-- and not pq.empty()){
            Tuple top = pq.top();
            pq.pop();
            int i = top.i, j = top.j;
            ans.push_back({nums1[i], nums2[j]});
            if(j + 1 < n2)
                pq.push(Tuple(i, j + 1, nums1[i], nums2[j + 1]));
        }
        
        return ans;
    }
};