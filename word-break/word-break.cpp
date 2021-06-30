/*
  Declare an array of size n+1. Here, each index of this array signifies if there is a dictionary word ending at that index.
dp[0] = 1, because empty string "" is a part of each dictionary word.

Now for, each iteration we check if there is a dictionary word ending at index i-1
i.e. dp[i-1] != 0, and if there is then we check if any word of the dictionary is equal to substring from index i-1 i.e. s.substr(i-1, d[j].size()) == d[j]) */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n+1, 0);
        dp[0] = 1;
       // cout<<wordDict.size();
        for (int i = 1; i < n+1; ++i)
        {
            for (int j = 0; j < wordDict.size(); ++j)
            {
                if (dp[i-1] && s.substr(i-1, wordDict[j].size()) == wordDict[j])
                    dp[i+wordDict[j].size()-1] = 1;
            }
        }
        return dp[n];
    }
}; /*
        
    if (wordDict.size() == 0) return false;
           int n=s.size();

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (dp[j])
        {
          string word = s.substr(j, i - j);
          if (find(wordDict.begin(),wordDict.end(),word) != wordDict.end())
          {
            dp[i] = true;
            break; 
          }
        }
      }
    }
    return dp[n];
  
    }
    }; */