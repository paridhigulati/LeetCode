class Solution {
public:
    
    
    bool isAns(int mid, int m, vector<int>& position)
    {
        
        int prev = position[0], count=1;
        int n = position.size();
        for(int i=1;i<n;i++)
        {
            if(position[i] - prev >= mid)
            {
                count +=1;
                prev = position[i];
                if(count == m )
                    return true;
            }
        }
        return count >= m ? true : false;
        
    }
    int maxDistance(vector<int>& position, int m) {
     
        int n = position.size();
        sort(position.begin(), position.end());
        int s = 1, e = position[n-1], ans=0;
        
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            
            if(isAns(mid, m, position))
            {
                ans = mid;
                s = mid+1; //try widening the gap
            }
            else
            {
                e = mid-1;//sufficient gap reached 
            }
        }
        return ans;
    }
};