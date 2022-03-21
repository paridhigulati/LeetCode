class Solution {
public:
    vector<int> partitionLabels(string s) {

        int str[26]={0};
        for(int i=0;i<s.size();i++)
        
         str[s[i]-'a'] = i;
        
        int start=0, end=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            end = max(end , str[s[i]-'a']);
             if(i==end){
            ans.push_back(i-start+1);
        start = i+1;
        }
        }
        return ans;

    }
};