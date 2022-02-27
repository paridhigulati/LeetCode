class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
      
        long long sum=0;
        long long t=1;
       long long end = LLONG_MAX;
        sort(time.begin(), time.end());
        while(t<=end)
        {
           long long mid= t+(end-t)/2;
            bool chk = solv2(time, totalTrips,mid);
            if(chk)
                end = mid-1;
            else
                    t=mid+1;
              
            }
        
        return t;
    }
bool solv2(vector<int>& time, int totalTrips, long long mid)
{
    long long tr=0;
    for(auto i : time)
    {
        tr += mid/i;
        if(tr>=totalTrips)
            return true;
    }
    return false;
}

       
          
};