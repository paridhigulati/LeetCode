class Solution {
public:
    
   
        int countAsterisks(string s) {
        
        int cnt=0, ans=0;
            for(int i=0;i<s.size();i++)
            {
                if(cnt % 2 == 0)
                {
                    if(s[i]=='*') ans++;
                }
                if(s[i] == '|') cnt++;
            }
            return ans;

    }
};
   