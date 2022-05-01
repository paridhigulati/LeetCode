class Solution {
public:
    string removeDigit(string number, char digit) {
        
        int n = number.size();
        string maxNum;
        
        for(int i=0;i<number.size();i++)
        {
            if(number[i] == digit)
            {
                maxNum = max(maxNum, number.substr(0,i) + number.substr(i+1));
            }
        }
        return maxNum;
    }
};