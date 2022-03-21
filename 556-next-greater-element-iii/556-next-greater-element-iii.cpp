class Solution {
public:
  //  int nextGreaterElement(long n) {
     
        
        // find the first dip which is the potential cadidate which has to be changed
        // swap that first dip char with its just next greater element and sort the rest in  ascending order
        
    int nextGreaterElement(long n) {

      string str = to_string(n);
    int index = str.size() - 2;
    
    while(index >= 0 && str[index] >= str[index + 1])
    {
        index--;
    }
    //no such greater element exists
    if(index == -1)
        return -1;
    
    //find val greater than str[index] and swap
    for(int i = str.size() - 1; i > index; i--)
    {
        if(str[i] > str[index])
        {
            // char temp = str[index];
            // str[index] = str[i];
            // str[i] = temp;
            swap(str[index], str[i]);
            break;
        }
    }
    //reverse the part after index
    reverse(str.begin() + index + 1, str.end());
    
    //if not in 32bit range return -1 otherwise covert string to int 
    return stoll(str) > INT_MAX ? -1 : stoi(str);
}
};