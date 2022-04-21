class MyHashSet {
    boolean[] isPresent;
    public MyHashSet() {
        isPresent = new boolean[1000000 + 1];
    }
    
    public void add(int key) {
        isPresent[key] = true;
    }
    
    public void remove(int key) {
        isPresent[key] = false;
    }
    
    public boolean contains(int key) {
        return isPresent[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */