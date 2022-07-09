class Solution {
public:
    
    int bits(int i)
    {
        int cnt=0;
        
           while(i > 0)
        {
            cnt+= i&1;
            
           i = i >> 1;
        }
        return cnt;
        }
    
    vector<int> countBits(int n) {
     
        vector<int>ans;
        int cnt=0;
        
        for(int i=0;i<=n;i++)
        {
            int bit = bits(i);
            ans.push_back(bit);
        }
     
        return ans;
    }
};
  
  




  