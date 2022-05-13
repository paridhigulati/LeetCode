class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int i=0, j=0;
        int ans = INT_MIN;
        // largest substring with atmost 2 unique elements
    
            map<int, int>freq;
        
        while( j < fruits.size())
        {
            freq[fruits[j]]++;
           
            if(freq.size() <= 2)
            {
                ans = max(ans, j-i+1);
            }
            else
            {
                freq[fruits[i]]--;
                
               if( freq[fruits[i]] == 0)
                   freq.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};