class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {  
        
        /*BRUTE FORCE complexity = o(nlogn)
        int n = nums.size();
       
        for(int i=0;i<nums.size();i++) // o(n)
        {
            nums[i] *= nums[i];
        }
         sort(nums.begin(), nums.end()); o(nlogn)
        return nums;
            
    }
}; */
        //OPTIMISED 2-POINTERS
        /*First why two pointers? Well, after a bit of thinking you may notice that after squaring numbers, all negative numbers are big ... they go down, meet at zero with positive numbers ... and then all those positive numbers are squared. So natural solution of merging two sorted lists from the middle will do. Just use two pointers that go from the middle outwards.*/


        int n = nums.size();
        vector<int> v(n);
        int l =0;
        int r = n-1;
          int max = n-1;
        while(max>=0)
        {
            int val1 = nums[l]*nums[l];
            int val2 = nums[r]*nums[r];
            if(val1 > val2)
               {
                   v[max] = val1;
                     l++;
               }
            else
            {
                v[max] = val2;
                  r--;
            }
            max--;
        }
           return v;
    }
};









    /*
        while(index>=0)
        {
            if(A[front]*A[front]>A[back]*A[back] )
            {
                sq[index]=A[front]*A[front];
                front++;
            }
            else
            {
                sq[index]=A[back]*A[back];
                back--;
            }
            index--;
        }
        return sq;
    }
}; */