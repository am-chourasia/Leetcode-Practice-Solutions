class FreqStack {
    std::map<int, stack<int>> stackMap;
    unordered_map<int, int> freq;
public:
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        int key = freq[val];
        stackMap[key].push(val);
    }
    
    int pop() {
        auto it = stackMap.rbegin();
        auto& st = it->second;
        int ans = st.top();
        freq[ans]--;
        st.pop();
        if(st.size() == 0)
            stackMap.erase(it->first);
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */