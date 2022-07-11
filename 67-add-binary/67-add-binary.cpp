class Solution {
public:
    string addBinary(string a, string b) {
        
        int carry=0, sum=0;
        string ans = "";
        int i=a.size()-1, j = b.size()-1;
        
        while(i>=0 || j>=0 || carry)
        {
           int x = i>=0 ? a[i--] - '0' : 0;
            int y = j>=0 ? b[j--]-'0' : 0;
            
            sum = x + y + carry;
            
           ans += to_string (sum%2);
            carry = sum/2;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
        