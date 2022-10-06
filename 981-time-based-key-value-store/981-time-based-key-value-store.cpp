class TimeMap {
    map<string, map<int, string>> hashMap;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (hashMap.find(key) == hashMap.end())
            return "";
        auto& values = hashMap[key];
        if (values.find(timestamp) != values.end())
            return values[timestamp];
        
        auto it = values.lower_bound(timestamp);
        if (it == values.begin())
            return "";
        --it;
        return it -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */