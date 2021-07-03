class Solution {
public:
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
        //recursively check each char 
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
           if(!st.count(s.substr(0,i)))
              continue;
            
              solve(st,s.substr(i),sent + s.substr(0, i) + " ");
                   }
    }
}; /*


void dfs(string s, string sentence, unordered_set<string>& setting)
{
    if(s.empty())
    {
        sentence.pop_back();
        sentences.push_back(sentence);
        return;
    }
    int n = s.size();
    for(int i = 1; i <= n; i++)
    {
        if(!setting.count(s.substr(0, i)))
            continue;
        dfs(s.substr(i), sentence + s.substr(0, i) + " ", setting);
    }
}
}; */