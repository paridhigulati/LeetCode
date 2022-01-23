class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
     
        string digits = "123456789";
        vector<int>ans;
        
        int nl = to_string(low).size();
        int nh = to_string(high).size();
        
        for(int i=nl;i<=nh;++i)
        {
          for(int j=0;j<10-i;++j)
          {
              int n= stoi(digits.substr(j,i));
                if(n>= low and n<=high)
                 ans.push_back(n);
          }
    }
        return ans;
    }
};