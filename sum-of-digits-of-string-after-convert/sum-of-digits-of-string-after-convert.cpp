class Solution {
public:
 /*   map<char,int>m;
    int getLucky(string s, int k) {
        int p=k-1;
        int j=1;
       int sum=0;
       for(char i='a';i<='z';i++){
           m[i]=j;
           j++;
       }
       string str="";
        for(int i=0;i<s.length();i++){
           str+=to_string(m[s[i]]); 
        }
        for(int i=0;i<str.length();i++){
            sum+=str[i]-'0';
        }
        while(p--){
            int n=sum;
            sum=0;
            while(n>0){
                sum+=n%10;
                n=n/10;
            }
        }
        return sum;
    }
}; */
    int getLucky(string &s, int k) 
{
	int result=0,n=s.length();
	for(int i=0;i<n;i++) 
        result+=(s[i]-'a'+1)/10+(s[i]-'a'+1)%10;

	for(int i=0;i<k-1;i++)
	{
		int t=0;
		while(result)
		{
			t+=result%10;
			result/=10;
		}
		result=t;
	}
	return result;
}
};