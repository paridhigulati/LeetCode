class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        
//         The approach is based on a fact that if slope of two lines are equal and they have a point in common , then it is the same line.


        sort(stockPrices.begin(), stockPrices.end());
       // if(slope remains of same sign , continue) else count++
        
       if(stockPrices.size()<=1)return 0;
        int lines = 1;
        for(int i =1;i<stockPrices.size()-1;i++){
           
            long double x1 = stockPrices[i-1][0];
            long double y1 = stockPrices[i-1][1];
                
            long double x2 = stockPrices[i][0];
            long double y2 = stockPrices[i][1];
            
            
            long double x3 = stockPrices[i+1][0];  
            long double y3 = stockPrices[i+1][1];
            
            
            
           long double a = (long double)(y2-y1)/(x2-x1);  // slope of line joining pts i , i-1
           long  double b = (long double)(y3-y2)/(x3-x2);  // slope of line joining pts i+1,i
            
            if(a!=b){
                              // since ith point is common , if slope a and b are equal then it is a straight line otherwise its not              
                lines ++;
            }
            
        }
        return lines;
    }
};