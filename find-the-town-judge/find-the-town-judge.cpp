class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // should be trusted by n-1 ppl and should trust 0 ppl 
       
        vector<pair<int,int>>arr(n+1, {0,0}); // first : how many he trusts 
        //second : how many trust him 
        for(int i=0;i<trust.size();i++)
        {
            arr[trust[i][0]].first += 1;
            arr[trust[i][1]].second += 1;
        }
        for(int i=1;i<=n;i++)
        
            if(arr[i].first==0 and arr[i].second==n-1)
                return i;
            
        return -1;
    }
};
   