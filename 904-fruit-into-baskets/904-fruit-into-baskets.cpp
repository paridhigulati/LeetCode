class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int i=0, j=0;
        int window = INT_MIN;
        
        unordered_map<int,int>mp;
        
        while( j < fruits.size())
        {
            mp[fruits[j]]++;
            
            if(mp.size() <= 2)
            {
                window = max(window, j-i+1);
            }
            else if(mp.size() > 2)
            {
                mp[fruits[i]]--;
                
                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                
                i++;
            }
            j++;
        }
        return window;
    }
};
            
            
            
            
            
            
     