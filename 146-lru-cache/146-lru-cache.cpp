struct Node{
    int key;
    int value;
    Node(int k, int v){
        key = k;
        value = v;
    }
};
class LRUCache {
    int capacity;
    std::unordered_map<int, std::list<Node>::iterator> mapping;
    std::list<Node> list;
public:
    LRUCache(int capacity) : capacity(capacity) {
    }
    
    int get(int key) {
        // if the key is not present:
        if(mapping.count(key) == 0)
            return -1;
        // transfer the accessed key to the beginning of the list.
        list.splice(list.begin(), list, mapping[key]);
        // no iterators or references become invalidated, the iterators to moved elements remain valid
        // therefore no need to change the mapping
        return mapping[key]->value;
    }
    
    void put(int key, int value) {
        // if the key is already present, update it's value
        if(get(key) != -1){
            mapping[key]->value = value; 
            return;    
        }
        // if capacity is full, delete the last used cache
        if(capacity == mapping.size()){
            mapping.erase(list.back().key);
            list.pop_back();
        }
        // adding node to map and at the front of the list:
        list.emplace_front(key, value);
        mapping[key] = list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */