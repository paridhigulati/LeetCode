class Solution {
public:
double dp[26][26][101];
    double knight(int n , int k, int row, int column){
         //base cases
          if(row <0 || column <0|| row>= n ||column >= n){
             return 0;
             }
          if(k ==0) return 1; // if k ie. no. of steps is 0 than the probabilty to have Knight on borad is 1
          if(dp[row][column][k]){
              return dp[row][column][k];
         }
          double sum =0; // to find the sum
        
         sum = knight(n, k-1, row-2, column -1) + knight(n, k-1, row-1, column -2) + 
            knight(n, k-1, row+2, column +1) + knight(n, k-1, row+1, column +2)+ 
            knight(n, k-1, row-2, column +1)+ knight(n, k-1, row+2, column -1) +
            knight(n, k-1, row-1, column +2) + knight(n, k-1, row+1, column -2);
          sum /= 8;
          return dp[row][column][k] = sum;
                                                            
    }
    double knightProbability(int n, int k, int row, int column) {
        return knight(n, k, row, column);
    }
};
/*when there is no movement i.e. when k is 0 there can be a probabilty of having knight at the chess borad is 1

At every step the knight has 8 choices to move some can be in the board and some can be out of it

the ones which are at the out of the board we can simply ignore that or make it a zero.

These are choices of Knight :
( row-2, column -1)
( row-1, column -2)
( row+2, column +1)
( row+1, column +2)
( row-2, column +1)
( row+2, column -1)
( row-1, column +2)
( row+1, column -2)*/