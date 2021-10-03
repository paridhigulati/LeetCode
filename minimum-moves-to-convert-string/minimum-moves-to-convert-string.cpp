class Solution {
public:
    int minimumMoves(string s) {
        
     int ans=0;
for(int i=0 ; i<s.length() ; i++)
{
    if(s[i]=='0') continue;
    else if(s[i]=='X')
    {
        i+=2;
        ans++;
    }
}
        return ans;
    }
};