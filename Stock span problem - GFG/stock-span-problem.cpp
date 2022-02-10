// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
        stack<pair<int,int>>st;
                vector<int>v;
        //int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(st.size()==0) v.push_back(-1);
        else if(!st.empty() and st.top().first > arr[i]) // NGL > arr[i]
         v.push_back(st.top().second); //index of NGL
        else if(!st.empty() and st.top().first <= arr[i])
        {
            while(!st.empty() and st.top().first <= arr[i])
            {
                st.pop();
            }
            if(st.size()==0)
                v.push_back(-1);
            else
                v.push_back(st.top().second);
        }
        st.push({arr[i], i});
    }
    
    for(int i=0;i<v.size();i++)
    {
        v[i] = i-v[i];
    }
    return v;
       // Your code here
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends