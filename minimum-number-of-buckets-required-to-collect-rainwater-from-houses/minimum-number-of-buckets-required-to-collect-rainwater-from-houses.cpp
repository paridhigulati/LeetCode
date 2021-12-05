class Solution {
public:
    int minimumBuckets(string street) {
     
        //greedy 
        int n = street.size();
        int ans =0;
        for(int i=0;i<n;)
        {
            if(street[i]=='H')
            {
            if(i+1 < n and street[i+1]=='.')
            {
                ans++; i+=3;
                continue;
            }
                else if(i-1 >=0 and street[i-1] == '.')
                {
                    ans++;
                    i++; continue;
                }
                return -1;
            }
            i++;
        }
        return ans;
    }
};