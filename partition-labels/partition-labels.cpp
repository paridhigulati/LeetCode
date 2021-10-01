class Solution {
public:
    vector<int> partitionLabels(string s) {
        int str[26]={0};
        for(int i=0;i<s.size();i++)
        
         str[s[i]-'a'] = i;
        int j=0, anchor = 0;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            j = max(j , str[s[i]-'a']);
             if(i==j){
            ans.push_back(i-anchor+1);
        anchor = i+1;
        }
        }
        return ans;

    }
};

        
      