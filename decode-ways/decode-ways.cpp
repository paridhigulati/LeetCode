
//3. Dynamic Programming [ faster than 100.00% ] [ TC: (n) ]

class Solution {
public:
    int numDecodings(string s,int n) {
	    //table to store results of subproblems 
         int count[n+1];  
        count[0] = 1; 
        count[1] = 1; 
		
		// for base condition "01123" should return 0 	
        if(s[0]=='0')   
             return 0; 
			 
       for (int i = 2; i <= n; i++){ 
            count[i] = 0; 
  
        // If the last digit is not 0,   then last digit must add to the number of words 
		
        if (s[i-1] > '0') 
            count[i] = count[i-1]; 
  
        // If second last digit is smaller  than 2 and last digit is smaller than 7,  then last two digits form a valid character 
		
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') ) 
            count[i] += count[i-2]; 
    } 
    return count[n];
    }
	
    int numDecodings(string s) {
        return numDecodings(s,s.size());
    }
	
};