class FreqStack {
public:
    
    unordered_map<int, int> mp;
    unordered_map<int, stack<int>> ds;
    int maxFreq=0;
  
    FreqStack() {
  
    }

    void push(int val) {

        mp[val]++;    
        maxFreq = max(maxFreq,mp[val]);
        ds[mp[val]].push(val);    
    }
    
    int pop() {
        if(maxFreq< 0) return -1;
        int ans = ds[maxFreq].top();
        ds[maxFreq].pop();
          mp[ans]--;
       
        //check if empty
        if(ds[maxFreq].size()==0)
        {
            ds.erase(maxFreq);
               maxFreq--;
        }
        
        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */