class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry =0;
        int i1= num1.size()-1;
        int i2 = num2.size()-1;
        string result;
        while(i1 >= 0 || i2 >= 0 || carry >= 1){
            int digit1 = i1 >= 0 ? num1[i1--] - '0' : 0;
            int digit2 = i2 >= 0 ? num2[i2--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum/10;
            sum = sum%10;
            result = to_string(sum) + result ;
        }
        return result == "" ? "0" : result;
    }
    
}; 