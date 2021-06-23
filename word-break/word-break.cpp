class Solution {
public:
   
bool wordBreak(string s, vector<string>& dict) 
    {
        if(dict.size() == 0)
            return false;
        int n = s.size();
        bool t[n + 1];
        memset(t, false, sizeof(t));
        t[0] = true;
        
         for(int i = 1; i <= s.size(); i++)
        {
            for(int j = i - 1;j >= 0; j--)
            {
                if(t[j])
                {
                    string str = s.substr(j, i - j);
					auto it = find(dict.begin(), dict.end(), str);   //search for str in dictionary
                    if(it != dict.end())
                    {
                        t[i] = true;
                        break; 
                    }
                }
            }
        }
        
        return t[n];
    }   
};