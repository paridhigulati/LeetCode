// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
          
    stack<int>st;
    //vector<int>v;
    int counter = 1;
    //st.push(counter);
    // counter++;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'D')
        {
            st.push(counter);
            counter++;
        }
        else if(s[i]=='I')
        {
            st.push(counter);
            counter++;
            while(!st.empty())
            {

                int t =st.top();
                st.pop();
                cout<<t;
            }
        }
       
    }
     st.push(counter);
     while(!st.empty())
     {
        cout<<st.top();
        st.pop();
}

    }
    
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends