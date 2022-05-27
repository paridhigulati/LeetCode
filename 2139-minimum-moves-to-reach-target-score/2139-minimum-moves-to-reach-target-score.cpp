class Solution {
public:
    int minMoves(int target, int maxDoubles) {
       
        int count =0;
        
        while(target != 1 and maxDoubles != 0)
        {
            
          if(target%2)
          {
              count++;
              target--;
          }
            else{
             count++;
                
                    target /= 2;
                    maxDoubles--;
                }
            
        }
        count += (target -1); //maxDoubles exhausted 
        return count;
    }
};