class Solution {
public:
    string removeOccurrences(string s, string part) {
     
  // USING STRINGS AS A STACK, compare top 3 elements of stack with part 
        
       /* We make a copy of our string s (x in code) and then iterate over the string s.
Now in the current iteration if j is greater than or equal to m that means that we have seen at least m elements, so we can check whether the substring of last m characters is equal to part or not. If it is equal, we reduce the variable 'j' by m showing that we have removed this substring and now we will overwrite the characters from index j.
Finally we will return the substring of x of length j.*/\
    
	  string temp = s; 
	int n = s.size(), m = part.size(), i, j;
	for (i = 0, j = 0; i < n; i++) {
		temp[j++] = s[i];
		if (j >= m && temp.substr(j - m, m) == part)
			j -= m;
	}
	return temp.substr(0, j);
}
};