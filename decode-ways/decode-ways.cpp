/*// sequential thought process for this problem

//1) If the last digit is non-zero, recur for remaining (n-1) digits and add the result to total count.
//2) If the last two digits form a valid char (or smaller than 27), recur for remaining (n-2) digits and add the result to total count.


//1.Recursion(TLE) [time complexity of the code is exponential]
class Solution {
public:
    int numDecodings(string s,int size) {
        if (s[0]=='0') 
          return 0;
        if (size == 0 || size == 1) 
            return 1; 
		// for base condition "01123" should return 0 	
        int output=0;
        if (s[size-1] > '0') 
           output=numDecodings(s,size-1);
        if (s[size-2] == '1' ||  (s[size-2] == '2' && s[size-1] < '7') ) {
            output+=numDecodings(s,size-2);
        }
        return output;
    }
	
    int numDecodings(string s) {
        cout<<s.size();
        return numDecodings(s,s.size());
    }
	
};

//2.memoization[faster than 100.00%]

class Solution {
public:
    int numDecodings(string s,int size,vector<int> &vec) {
        if (s[0]=='0') 
          return 0;
        if (size == 0 || size == 1) 
            return 1;
        if(vec[size]!=-1){
            return vec[size];
        }
        int output=0;
        if (s[size-1] > '0') 
           output=numDecodings(s,size-1,vec);
        if (s[size-2] == '1' ||  (s[size-2] == '2' && s[size-1] < '7') )
           output+=numDecodings(s,size-2,vec);
        vec[size]=output;
        return output;
    }
	
    int numDecodings(string s) {
        vector<int> vec(s.size()+1,-1);
        return numDecodings(s,s.size(),vec);
    }
	
};

*/

//3. Dynamic Programming [ faster than 100.00% ] [ TC: (n) ]

class Solution {
public:
    int numDecodings(string s,int n) {
	    //table to store results of subproblems 
         int dp[n+1];  
        dp[0] = 1; 
        dp[1] = 1; 
		
		// for base condition "01123" should return 0 	
        if(s[0]=='0')   
             return 0; 
			 
       for (int i = 2; i <= n; i++){ 
            dp[i] = 0; 
  
        // If the last digit is not 0,   then last digit must add to the number of words 
		
        if (s[i-1] > '0') 
            dp[i] = dp[i-1]; // e.g 231 here add no. of ways of 23 to 1 
  
        // If second last digit is smaller  than 2 and last digit is smaller than 7,  then last two digits form a valid character 
		
        if ( (s[i-2]== '1' || s[i-2] == '2' && s[i-1] < '7') )  //e.g in 231, 2 31 here 31 is invalid 
            dp[i] += dp[i-2]; 
    } 
    return dp[n];
    }
	
    int numDecodings(string s) {
        return numDecodings(s,s.size());
    }
	
};