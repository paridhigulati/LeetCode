class Solution{
    public:
vector<int> executeInstructions(int n, vector<int>& sP, string s){
    int m= s.size(),j=0;
    vector<int> ans(m);
	
    while(j<m){
	
        //come back to starting again
        int startRow= sP[0];
        int startCol= sP[1];
        int cnt=0;
		
        for(int k=j;k<m;k++){
		
            if(s[k]=='U' and startRow-1>=0){
                cnt++;
                startRow--; //move to that direction
            }  
			
            else if(s[k]=='R' and startCol+1<n){
                cnt++;
                startCol++; //move to that direction
            } 
			
            else if(s[k]=='L' and startCol-1>=0){
                cnt++;
                startCol--; //move to that direction
            } 
			
            else if(s[k]=='D' and startRow+1<n){
                cnt++;
                startRow++; //move to that direction
            }

            else
                break;         //we can not move forward hence break from here as we are not allowed 
        
		}
        
		ans[j++]=cnt;
    
	}
    return ans;
}
};