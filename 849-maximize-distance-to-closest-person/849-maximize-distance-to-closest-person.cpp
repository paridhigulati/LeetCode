class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
     // creating variable
        int n = seats.size();
        int empty = 0; // no of current empty chairs i.e. consecutive zeros update it & Whenever we encounter 1 we reset it to 0
        int result = 0;
        int idx1 = -1, idx2 = -1; // intializing with invalid index and 1st time we encounter 1 we will update it with their index & then we never change it. 

        for(int i = 0; i < n; i++){
            if(seats[i] == 1){ // so when we encounter 1 i.e. occupied
                empty = 0; // reset it
                if(idx1 == -1) idx1 = i; // updating for left most "1"
                idx2 = i; // updating for right most "1"
            }
            else{ // if it's not 1 it's 0;
                empty++; // update
                result = max(result, (empty + 1) / 2); // compare the maximum with internal chair
            }
        }
        result = max({result, idx1, n - 1 - idx2}); // get the max of internal, starting consecutive zeros, end consecutive zeros
return result;
    }
};