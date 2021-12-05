class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
     /* brute
        map<string,int>m1,m2;
     
        for(auto &i : words1)
        {
            m1[i]++;
        }
        for(auto &i : words2)
        {
            m2[i]++;
        }
        int cnt =0;
        for(auto i : m1)
        {
            if(i.second == 1)
            {
                if(m2[i.first] == 1)
                    cnt++;
            }
        }
        return cnt;*/
        
        // better -> 1 map 
        map<string, int>m1;
        for(auto i : words1)
         m1[i]++;
        for(auto i : words2)
        {
        if(m1[i] < 2)
            m1[i]--;
        }
        int cnt =0;
        for(auto i : m1)
        {
            if(i.second == 0)
            {
                cnt++;
            }
        }
        
        
        
        return cnt;
        
        
    }
};