class Solution {
public:
    #define ll long long 
    
    int countHillValley(vector<int>& a) {
  int cnt=0;
       int n = a[0];
vector<int>c;
        c.push_back(a[0]);
        for(int i=1;i<a.size();i++)
        {
            if(a[i] != n)
                c.push_back(a[i]);
            n = a[i];
                
        }
        
     
        for(int i=1;i<c.size()-1;i++)
        {
            if( c[i] > c[i-1] and c[i] > c[i+1] or c[i] < c[i-1] and c[i] < c[i+1])
            cnt++;
        }
            return cnt;
    }
	
};