class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        vector<int>x = {startPos[0], homePos[0]};
        vector<int>y= {startPos[1], homePos[1]};
        int ans =0;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        for(int i=x[0];i<=x[1];i++)
        {
            if(i==startPos[0]) continue;
            ans+=rowCosts[i];
        }
           
        for(int i=y[0];i<=y[1];i++)
        {
            if(i==startPos[1]) continue;
            ans+=colCosts[i];
        }
        return ans;
    }
};