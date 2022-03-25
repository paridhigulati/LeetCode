class Solution {
public:
    
    bool static comp(vector<int> &a, vector<int> & b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       
        int cnt=0, ans=0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
       for(int i=0;i<boxTypes.size();i++)
        {
             cnt = min(truckSize, boxTypes[i][0]);
             ans += (cnt * boxTypes[i][1]);
            truckSize -= cnt;
            if(truckSize == 0)
                break;
        }
        return ans;
    }
    
};