class Solution {
public:
//     int minDays(int n) {
        //>10^8 suggests a logn solution so we get an idea of bfs .
        // space ~ height of tree ~ logn 
        
// day 0: [11]
// day 1: [10]
// day 2: [5, 9]
// day 3: [3, 4, 8]
// day 4: [1, 2, 3, 4, 7]
// day 5: [0, 1, 2, 3, 6]

        int minDays(int n) {
            
        queue<int>q;
        q.push(n);
        int moves=0;
        set<int>s;
        s.insert(n);
            
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int k=q.front();
                q.pop();
                if(k==0){
                return moves;
                }
                if(s.find(k-1)==s.end()){
                    q.push(k-1);
                    s.insert(k-1);
                }
                if(k%2==0 && s.find(k/2)==s.end()){
                    q.push(k/2);
                    s.insert(k/2);
                }
                if(k%3==0 && s.find(k/3)==s.end()){
                    q.push(k/3);
                    s.insert(k/3);
                }
            }
            moves++;
            
        }
        return moves;
        
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
// private:
//     int inner(int n) {
//         if (dp.find(n) != dp.end()) {
//             return dp[n];
//         }
//         int result = INT_MAX;
// 		// from large partitions to small
//         if (n % 3 == 0) result = min(result, inner(n/3));
//         if (n % 2 == 0) result = min(result, inner(n/2));
// 		// we don't want to do this step as this is the most expensive 
// 		// we don't need to do this if number was divisible by both
//         if (n % 3 != 0 || n% 2 != 0) result = min(result, inner(n-1));
//         dp[n] = result + 1;
//         return dp[n];
//     }
// public: 
//     unordered_map<int, int> dp;
//     int minDays(int n) {
//         dp[0] = 0;
//         dp[1] = 1;
//         return inner(n);
//     }
// };