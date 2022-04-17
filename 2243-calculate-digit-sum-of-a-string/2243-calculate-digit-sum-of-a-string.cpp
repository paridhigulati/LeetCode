class Solution {
public:
    string digitSum(string s, int k) {

         
        while(s.size() > k)
        {
             string newStr = "";
        for(int i=0;i<s.size();i+=k)
        {
           string v = s.substr(i,k);
            
            int sum = 0;
            
            for(int j=0;j<v.size();j++)
            {
                sum += v[j]-'0';
            }
            newStr += to_string(sum);
        }
            s = newStr;
        }
        return s;
    }
};