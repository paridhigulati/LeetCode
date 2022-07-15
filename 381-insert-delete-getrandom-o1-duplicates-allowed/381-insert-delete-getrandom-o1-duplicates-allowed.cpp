class RandomizedCollection {
    private: unordered_map<int, set<int>>mp;
    vector<int>nums;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) 
    {        
        mp[val].insert(nums.size());
        nums.push_back(val);
        
        return mp[val].size() == 1;
    }
    
    bool remove(int val) 
    {
        auto it = mp.find(val);
        if(it == mp.end())
            return false;
        int indexToRemove = *(mp[val].begin());  // find the index of any of the occurance of val to be removed
        mp[val].erase(indexToRemove);   // remove that index of val from map
        int lastElem = nums.back();
        nums[indexToRemove] = lastElem; // replace that occurance val with the last element
        
        mp[lastElem].insert(indexToRemove);    // insert new index for last element of nums
        mp[lastElem].erase(nums.size() - 1);  // remove old index of last element
        nums.pop_back();    // remove the last element
        
        // if size of set becomes 0 at mp[val] i.e. val was unique
        if(mp[val].empty())
            mp.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        return nums[rand() % nums.size()];
    }
};
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */