class Solution {
public:

    int sumSubarrayMins(vector<int>& a) {
//brute n^2
// 	   int sum = 0;
//         for(int i = 0; i < arr.size(); i++){
//             int minVal = arr[i];
//             for(int j = i; j < arr.size(); j++){
//                 minVal = min(minVal, arr[j]);
//                 sum = (sum + minVal) % 1000000007;
//             }
//         }
        
//         return sum;
        
        // optimal ->O(n) : number of times x is minimum in each subarray 
        
       if (a.size() == 0)  return 0;
        long long mod = 1e9+7;
        stack<pair <int, int>> s1,s2;
        int left[a.size()],right[a.size()];
        for(int i=0;i<a.size();i++){
            int count=1;
            while(!s1.empty()&& s1.top().first>a[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push(make_pair(a[i],count));
            left[i]=count;
        }
        for(int i=a.size()-1;i>=0;i--){
            int count=1;
            while(!s2.empty()&& s2.top().first>=a[i]){
                count+=s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(a[i],count));
            right[i]=count;
        }
        long long ans=0;
        for(int i=0;i<a.size();i++){
            ans = ans + (long long) (left[i]) * (long long) right[i]* (long long) a[i] % mod;
            ans%=mod;
        }
        return (int) ans;
    }
};
//   long long int sum=0, mod=1e9+7;
//         for(int i=0;i<n;i++)
//         {
//             sum = (sum+(long long)arr[i]*(long long)(i-left[i])*(long long)(right[i]-i))%mod;
//         }
        
//         return sum;