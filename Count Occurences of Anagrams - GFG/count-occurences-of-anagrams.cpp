// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    int i=0,j=0;
	    int n = txt.size();
	    int k = pat.size();
	    
	    vector<int>pattern(26,0);
	    vector<int>hash(26,0);
	    
	    int count = 0;
	    
	    for(char ch : pat)
	    {
	        pattern[ch-'a']++;
	    }
	    
	    while(j < n)
	    {
	        hash[txt[j] - 'a']++;
	        
	        if(j-i+1 < k)
	        j++;
	        
	        else if(j-i+1 == k)
	        {
	            if(pattern == hash)
	            {
	                count++;
	            }
	            
	            if(hash[txt[i]-'a'] != 0)
	            hash[txt[i]- 'a']--;
	            
	            i++; j++;
	        }
	    }
	    return count;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends