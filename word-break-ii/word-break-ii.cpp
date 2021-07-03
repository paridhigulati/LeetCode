class Solution {
public:
    /*
    //BACKTRACKING METHOD 1 BRUTE  
    vector<string>sentence;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        st.insert(wordDict.begin(), wordDict.end());
        solve(st, s, "");
        return sentence;
    }
    void solve(unordered_set<string>st, string s, string sent)
    {
        //bases cases
        if(s.empty())
        {   
        sent.pop_back();
        sentence.push_back(sent);
        return;
        }
        //recursively check each char and check whther that given substring exist in set else backtrack
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
           if(!st.count(s.substr(0,i)))  // if that substring is not found 
              continue; // backtrack
            
              solve(st,s.substr(i),sent + s.substr(0, i) + " "); //moving to next char 
                   }
    }
}; 

To SOLVE THE PROBLEM OF REPEATING SUBPROBLEMS, WE WILL MEMOIZE IT AND USE A MAP

*/
    

    map <string, vector<string>> dp;
    
    vector<string> ff(string s, set<string>& word_dict) {
        vector<string> res;
        if (dp.find(s) != dp.end()) return dp[s];
        
        for (int i = 1; i <= s.size(); i++) {
            if (word_dict.find(s.substr(0, i)) != word_dict.end()) {
                if (s.substr(i).length() == 0) {
                    res.push_back(s.substr(0, i));
                }
                else {
                    vector<string> subList = ff(s.substr(i), word_dict);
                    for (auto sub : subList) res.push_back(s.substr(0, i) + " " + sub);
                }
            }
        }
        
        return dp[s] = res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set <string> word_dict(wordDict.begin(), wordDict.end());
        return ff(s, word_dict);
    }
};