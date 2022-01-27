// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        long long required(long long arr[], long long n, long long k) {
        // Your code goes here
     
long long maxi = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > maxi)
            maxi = arr[i];
            
        }
        if(k>= maxi)
        return -1;
        else
        return maxi-k;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        cout << ob.required(arr, n, k) << endl;
    }
    return 0;
}  // } Driver Code Ends