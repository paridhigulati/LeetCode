class Solution {
public:
    
    void getPerm(string& num)
    {
        int n = num.size();
        int index = n-2;
       
        while(index>=0 and num[index] >= num[index+1])
        {
            index--;
        }
       
        
        for(int i=n-1; i>index;i--)
        {
            if(num[i] > num[index])
            {
                swap(num[index], num[i]);
                break;
                
        }
    }
        reverse(num.begin()+index+1, num.end());
        
    
    }
        
    int getMinSwaps(string num, int k) {
        
        string val = num;
     
        while(k--)
        
            getPerm(val);
          
         
        int ans = 0 , n = num.length();
		//now compare num and val to find minimum number of adjancent swappings
		//for each num[i] move it to its corresponding position in 'val' by swapping adjacent elements.
		//Count each such swap
        for(int i=0;i<n;i++){
            if(num[i] != val[i]) {
                int j = i+1;
                while(num[j] != val[i]) 
                    j++;
                while(i<j) {
                    swap(num[j] , num[j-1]);
                    j--;
                    ans++;
                }
            }
        }        
        return ans;
    }
};