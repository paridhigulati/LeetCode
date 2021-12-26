class Solution {
public:
/*      int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
    bool isSameAfterReversals(int num) {
        if(num==0)
       return true;
      else
      {
        int rev = reverse(num);
        int rev2 = reverse(rev);
        if(rev2 == num)
        return true; 
      }
        return false;
    }
};
*/  
     bool isSameAfterReversals(int num) {
    if(num<10)
        {
            return 1;
        }
        if(num%10==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
    }
};