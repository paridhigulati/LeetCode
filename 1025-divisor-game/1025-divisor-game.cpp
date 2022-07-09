class Solution {
public:
 
    
     bool func(int n, vector<int> &arr){
        if (n==0) return true;
        if (arr[n] != -1) return arr[n];
        
        for (int x = 1; x < n; x++){
            if (n%x==0){
                return arr[n] = !func(n-x, arr);
            }
        }
        return arr[n] =  false;
    }
    
    bool divisorGame(int n) {
        vector<int> arr(1001, -1);
        return func(n, arr);
    }
};