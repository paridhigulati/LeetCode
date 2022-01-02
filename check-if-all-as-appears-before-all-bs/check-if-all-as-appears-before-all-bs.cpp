class Solution {
public:
    bool checkString(string s) {
    //    string str = "ba";
        
      //  if (s.find(str) != std::string::npos) {
        
        string s1 = s;
        sort(s1.begin(), s1.end());
        if(s!=s1)
        {
            return false;
        }
        return true;
    }
};