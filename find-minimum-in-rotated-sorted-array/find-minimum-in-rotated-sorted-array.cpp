class Solution {
public:
    int findMin(vector<int>& num) {
     
        //observation -> min will be first index 
        // 4 5 6 7 8 0 1 2 so min(0) is the only element which is smaller than the one on left and (8) max is the only element is which is greater on right 
        // ans will lie in this unsorted type region 
  
        
  
        int low = 0, high = num.size() - 1;
        // loop invariant: 1. low < high
        //                 2. mid != high and thus A[mid] != A[high] (no duplicate exists)
        //                 3. minimum is between [low, high]
        // The proof that the loop will exit: after each iteration either the 'high' decreases
        // or the 'low' increases, so the interval [low, high] will always shrink.
        while (low < high) {
            auto mid = low + (high - low) / 2;
            if (num[mid] < num[high])  
                // the mininum is in the left part
                high = mid;
            else if (num[mid] > num[high])
                // the mininum is in the right part
                low = mid + 1;
        }

        return num[low];
    }
};