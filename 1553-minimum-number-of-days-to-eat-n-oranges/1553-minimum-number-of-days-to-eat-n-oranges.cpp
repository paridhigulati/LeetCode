class Solution {
// public:
//     int minDays(int n) {
        //>10^8 suggests a logn solution so we get an idea of bfs .
        // space ~ height of tree ~ logn 
        

//         queue<int>q;
//         q.push(n);
//         int cnt=0;
//         while(!q.empty()){
//             int sz=q.size();
//             set<int>s;
//                 for(int i=0;i<sz;i++)
//                 {
//                     int x=q.front();
//                     q.pop();
//                     if(x==0)return cnt;
//                     s.insert(x-1);
//                     if(x%2==0)
//                         s.insert(x/2);
//                     if(x%3==0)
//                     s.insert(x-2*(x/3));
//                 }
//             for(auto x: s)
//                 q.push(x);
//                  cnt++;
//         }
//         return 0;

//     }
// };
private:
    int inner(int n) {
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        int result = INT_MAX;
		// from large partitions to small
        if (n % 3 == 0) result = min(result, inner(n/3));
        if (n % 2 == 0) result = min(result, inner(n/2));
		// we don't want to do this step as this is the most expensive 
		// we don't need to do this if number was divisible by both
        if (n % 3 != 0 || n% 2 != 0) result = min(result, inner(n-1));
        dp[n] = result + 1;
        return dp[n];
    }
public: 
    unordered_map<int, int> dp;
    int minDays(int n) {
        dp[0] = 0;
        dp[1] = 1;
        return inner(n);
    }
};