class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       
        // right min
        // left max
    // count chunks 
        int n = arr.size();
        vector<int>rmin(n+1);
         rmin[arr.size()] = INT_MAX;
        
        for(int i=n-1;i>=0;i--)
        {
            rmin[i] = min(rmin[i+1], arr[i]);
        }
        int lmax = INT_MIN, count=0;
        
        for(int i=0;i<arr.size();i++)
        {
            lmax = max(lmax, arr[i]);
            
            if(lmax <= rmin[i+1])
                count++;
        }
        return count;
        
        
        
        
        
    }
};