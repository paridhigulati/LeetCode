class MyHashMap {
    
      private : vector<vector<pair<int,int>>>v;
    const int size = 1000;
public:
    MyHashMap() {
        
     v.resize(size);
    }
    
    void put(int key, int value) {
        
        // pehle se exist , ++ else add
        if(v[key%size].size()==0)
        {
            v[key%size].push_back({key,value});
        }
           else
        {
            bool flag=1;
            for(int i=0;i<v[key%size].size();i++)
            {
                if(v[key%size][i].first==key)
                  {  
                    v[key%size][i].second=value;
                    flag=0;
                  }
            }
            if(flag)
            {
                 v[key%size].push_back({key,value});
            }
            
        }
        
    }
        
    
    int get(int key) {
     
        // agar exist krta h to return value else  -1 
       for(int i=0;i<v[key%size].size();i++)
            {
                if(v[key%size][i].first==key)
                  {  
                     return v[key%size][i].second; 
                  }
            }
        return -1;
    }
    void remove(int key) {
         
          for(int i=0;i<v[key%size].size();i++)
            {
                if(v[key%size][i].first==key)
                  {  
                    v[key%size].erase(v[key%size].begin()+i); 
        }
    }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */