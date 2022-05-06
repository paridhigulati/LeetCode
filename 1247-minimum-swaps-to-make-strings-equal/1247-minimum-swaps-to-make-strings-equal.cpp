class Solution {
public:
    int minimumSwap(string s1, string s2) {
     
        if(s1.empty())return 0;
    int n=s1.size();
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i]){}
        else{
            if(s1[i]=='x')
                a++;
            else
                b++;
        }
    }
    int sum=(a/2)+(b/2);
    if((a+b)%2!=0)
        return -1;
    else{
        if(a%2==0){
            return sum;
        }
        else{
            return sum+2;
        }
    }
}

    
};