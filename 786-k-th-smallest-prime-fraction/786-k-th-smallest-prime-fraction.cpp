struct Tuple{
    int i;
    int j;
    int nums_i;
    int nums_j;
    Tuple(){
        i = j = nums_i = nums_j = -1;
    }
    Tuple(int i, int j, int nums_i, int nums_j){
        this->i = i;
        this->j = j;
        this->nums_i = nums_i;
        this->nums_j = nums_j;
    }
    bool hasNext(){
        return j - 1 != i;
    }
    pair<int, int> next(){
        return {i, j - 1};
    }
};

struct Compare {
    bool operator()(Tuple const& t1, Tuple const& t2)
    {
        if(t1.nums_i * t2.nums_j > t1.nums_j * t2.nums_i)
            return true;
        return false;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        int len = nums.size();
        priority_queue<Tuple, vector<Tuple>, Compare> pq;
        for(int i = 0; i < len - 1; i++){
            Tuple tup(i, len - 1, nums[i], nums[len - 1]);
            pq.push(tup);
        }
        
        int extracted = 0;
        Tuple top;
        while(extracted < k){
            top = pq.top();
            pq.pop();
            if(top.hasNext()){
                auto p = top.next();
                int i = p.first, j = p.second;
                Tuple next = Tuple(i, j, nums[i], nums[j]);
                pq.push(next);
            }
            extracted++;
        }
        
        vector<int> ans({top.nums_i, top.nums_j});
        return ans;
    }
};