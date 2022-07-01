class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return b[1] < a[1];
    }
    
   int maximumUnits(vector<vector<int>>& b, int truckSize) {
        
       sort(b.begin(), b.end(), cmp);
       int sum = 0;
       int prod = 0;
       for(int i=0;i<b.size();i++)
       {
           sum += b[i][0];
            if( sum >= truckSize)
        {
            sum -= b[i][0];
            prod += b[i][1] * (truckSize-sum);
                break;
        }
           else{
               prod +=  b[i][1] * b[i][0];
       }
        
       }      
            
       return prod;
    }
};