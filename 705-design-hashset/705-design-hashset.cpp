class MyHashSet {
    
    private : 
     vector<list<int>>v; 
     int size;
    
public:
    
    MyHashSet()
    {
      size = 1e6 + 1;
    
     v.resize(size);
    }
    
    //hash function 
    
     int hash(int key )
     {
       return  key % size ;
     }
    
    //function to search through the linked list 
    list<int> :: iterator search(int key)
    {
        int index = hash(key);
       return find(v[index].begin() , v[index].end(), key );
            
    }
    void add(int key) {
        
        //check if already present 
        if(contains(key)) return;
        
        int index=  hash(key);
        v[index].push_back(key);
    }
    
    void remove(int key) {
        
       if(!contains(key)) return;
        
        int index = hash(key);
        v[index].erase(search(key));
        
        
    }
    
    bool contains(int key) {
        
        int index = hash(key);
        if (search(key) != v[index].end()) return true;
        
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