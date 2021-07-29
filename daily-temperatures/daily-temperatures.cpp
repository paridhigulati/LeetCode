
  /* The solution is based on the simple logic that if you start from the right

You can keep track of the numbers seen so that when you move left -> That left element already knows which is the maximum number it will encounter
If the current number is smaller than the previously seen number -> Simply get the diff in the positions and insert into the stack
If the number is greater than the previously seen in stack -> Keep removing all the numbers (Since we need to find the number larger than it. IF found then great if not then it has result 0).
One great reason you can just remove the smaller numbers from stack(seen in right) is that now that we have current number larger than its right elements -> Hence for the lefter elements THIS CURRENT element will itself be the nearest largest number

*/
  class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty())
        {
            return vector<int>();
        }
        
		// A stack with values:  
		// <T[i], Number of days to the next larger number in T>
        stack<pair<int, int>> s;
		
		// The last number in T must have no value larger than it.
        s.push(make_pair(T.back(), 0));
        
        vector<int> ans(T.size(), 0);
        
		// Start from the back.
        for (int i = T.size() - 2; i >= 0; i--)
        {
            int counter = 1;
            
			// Pop the stack until its empty or the top number is smaller or equal to T[i]
			// The counter + the number of elements to the next larger number in T.
            while (!s.empty() && T[i] >= s.top().first)
            {
                counter += s.top().second;
                s.pop();
            }
            
			// If no number on stack is larger than T[i].
            if (s.empty())
            {
                s.push(make_pair(T[i], 0));
            }
            else
            {
                s.push(make_pair(T[i], counter));
                ans[i] = counter;
            }
        }
        
        return ans;
    }
};