class Solution {
public:
    
    
    bool canCarry(int mid, vector<int>& a, int days)
    {
        
        int sum=0, cnt=0;
        for(int i=0;i<a.size();i++)
        {
            if(sum + a[i] > mid)
            {
                cnt++;
                sum = a[i];
            }
            else 
                sum += a[i];
        }
        cnt++;
        return cnt <= days;
        
        
    }
    int shipWithinDays(vector<int>& a, int days) {
     
     int low =  *max_element(a.begin(), a.end()) ;
        
        int high = accumulate(a.begin(), a.end(),0);
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            // now divide such that subset sum is less than mid 
            
            if(canCarry(mid, a, days))
                high = mid-1;
            else 
                low = mid+1;
        }
            return low;
    
    }
};