class MyHashSet {
    
    private: 
      vector<bool>v;
public:
    MyHashSet() : v(1e6 + 1, false) {}
  
    
    void add(int key) {
        
        v[key] = true;
    } 
    
    void remove(int key) {
        v[key] = false;
    }
    
    bool contains(int key) {
        
        if(v[key])
        return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */