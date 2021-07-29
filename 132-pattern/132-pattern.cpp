class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //approach from right end num[k] < num[j]  gives single pass 
    
        /* brute force O(n^3)
        if (nums.size() < 3)
            return false;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    int one = nums[i];
                    int two = nums[j];
                    int three = nums[k];
                    if (one < three && three < two)
                        return true;
                }
            }
        }
        return false;
    } 
    }; 
    
  
//o(n^2)
    int n = nums.size();   
int mini = nums[0];
for(int j=1;j<n-1;j++)
{
    for(int k = j+1;k<n;k++)
    {
        if(nums[k] < nums[j] and nums[k] > mini)
        {  return true;}
       
    }
     mini = min(mini, nums[j]);
}
        return false;
    }
};




// o (n) using stack 
        int n = nums.size();
        int mini[n] ;
        mini[0]= nums[0];
        for(int i=1;i<n;i++)
        mini[i] = min(nums[i], mini[i-1]);
        stack<int>st;
        for(int j=n-1;j>=0;j--)
        {
            if(nums[j] > mini[j])
                while(!st.empty() and st.top() <= mini[j])
                    st.pop();
            if(!st.empty() and st.top() < nums[j]){
                return true;
            st.push(nums[j]);
        }
        }
    return false;
    }
}; */
          
        int two = INT_MIN;
        int index = nums.size();
        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] < two) 
                return true;
            while (index < nums.size() && nums[i] > nums[index]) {
                two = nums[index++];
            }
            nums[--index] = nums[i];
        }
        return false;
    } };
