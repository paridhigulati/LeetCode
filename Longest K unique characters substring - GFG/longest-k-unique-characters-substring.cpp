// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char, int>mp;
        //set<int>st;
        int window = -1, j=0, i=0;
       
       while(j<s.size())
        {
            //st.insert(s[j]);
            mp[s[j]]++;
            if(mp.size() <k)
            j++;
            else if(mp.size() == k)
            {
                window = max(window, (j-i+1));
                j++;
            }
            else if(mp.size() > k)
            {
                while(mp.size() > k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    mp.erase(s[i]);
                
                i++;
            }
            j++;
            }
            // while(st.size() == k)
            // {
            //     window = max(window, (j-i)+1);
            //     st.erase(s[i]);
            // }
            // j++;
        }
        return window;
        
    // your code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends