//need to sort the data in such a way most recently used and least recently used is sorted 
//cant use vector for that. beech mai se nikal kr aage dalna hoga so using doubly LL 



class LRUCache {
    private: 
    unordered_map<int,int>mp;
    unordered_map<int, list<int> :: iterator>address; // maps key to corresponding node in LL 
    list<int>dll;
    int size; //elements stored till now 
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        
         if(mp.find(key) == mp.end())    
        return -1;
                //to make it most recently : need to get the node and for that we make another map
        
       list<int> :: iterator it = address[key]; //node ka address pta chlgya jaha delete krna h
        
        dll.erase(it);
        address.erase(key); //map mai se bhi delete
        dll.push_front(key); //list ke head mai insert
        address[key] = dll.begin(); //map mai list ka address update 
        return mp[key];
        
       
    }
    
    void put(int key, int value) {
        
        //key already exist, not key-value pair so purani wali delete krdo aur new updae
        if(mp.find(key) != mp.end())
        {
            dll.erase(address[key]);
              address.erase(key);
               mp.erase(key);
            size--;
        }
        if(size == cap)
        {
        int keyy =  dll.back();
        dll.pop_back();
        address.erase(keyy);
        mp.erase(keyy);
        size--;
    }
        
        size++;
        dll.push_front(key);
        address[key] = dll.begin();
         mp[key] = value;
        
        
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */