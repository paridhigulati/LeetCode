//need to sort the data in such a way most recently used and least recently used is sorted 
//cant use vector for that. beech mai se nikal kr aage dalna hoga so using doubly LL 



class LRUCache {
     private: 
    //One map to store the key and its corresponding value to facilitate O(1) time complexity

     unordered_map<int,int>mp;
    //Similarly, one map to store the key and its corresponding positionn in the list
     unordered_map<int, list<int> :: iterator>address; // maps key to corresponding node in LL 
    //A doubly linked list of keys

     list<int>dll;
    //Global variable siz and cap for other functions to know size and the total capacity of the cache

    int size; //elements stored till now 
     int cap;
 public:
     LRUCache(int capacity) {
       cap=capacity;//Initializing the LRU cache with the given positive size capacity.
        size=0;//Keeping count of the total existing elements, which is initially 0
}
     int get(int key) {
        
         if(mp.find(key) == mp.end())    
        return -1;
//                 //to make it most recently : need to get the node and for that we make another map
        

        //Since key exists we have to move key to front of the list (as it is now the least recently used cache) and return val
        
        //So, firstly erase key and its old position
        list<int> :: iterator it = address[key]; //node ka address pta chlgya jaha delete krna h
        //Get the position of key in the list. This helps for searching list in O(1) throughout code.
        dll.erase(it);
        address.erase(key); //map mai se bhi delete
        dll.push_front(key); //list ke head mai insert
 //Now push the key at front of the list and update its position in our map
         address[key] = dll.begin(); //map mai list ka address update 
         return mp[key];
        
       
     }
            /*\U0001f4a1We have to place the key at front as it is now the LRU .
        If it already exists in the cache so firstly delete it and put up front.
        Also we have to evict the last key from our list if the capacity is already full. 
        Will write similar code like get () and simply mantain the data strucure we have created to facilitate O(1) average time complexity. */
     void put(int key, int value) {
        
//         //key already exist, not key-value pair so purani wali delete krdo aur new updae
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

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */
    

	
 
        
     
        
     
    
	
  