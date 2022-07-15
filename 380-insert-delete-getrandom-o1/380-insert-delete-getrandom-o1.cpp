class RandomizedSet {
    
    private: 
    unordered_map<int,int>mp;
    vector<int>v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //check if already present in map, continue
        if(mp.find(val) != mp.end())
            return false;
        else
        {
            v.push_back(val);
            mp[val] = v.size()-1;
             return true;
        }
        
    }
    
    bool remove(int val) {
       // first check in map if it is present then copy the last element to this elements index and update the index in map  
        if(!mp.count(val)) return false;
        
        mp[v.back()] = mp[val];
        swap(v.back(), v[mp[val]]);
        
        v.pop_back();
        mp.erase(val);
      return true;  
    }
    
    int getRandom() {
      return  v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */