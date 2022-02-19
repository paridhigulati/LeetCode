class Solution {
public:
    string removeKdigits(string num, int k) {
      	stack<char> st;
	for(int i=0; i<num.size(); i++){
		// Popping elements if greater than current digit and when k>0
		while(!st.empty() && st.top() > num[i] && k>0){
			st.pop();
			k--;
		}
		st.push(num[i]);
	}

	// Ex: "12345", k=3
	// For the above example, while inserting the elements, no element will be popped
	// But we need to remove 'k' characters 
	// Hence remove the top k characters
	while(k!=0){
		st.pop();
		k--;
	}
	
	// Storing stack elements in ans
	string ans;
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	
	// Removing leading zeroes
	while(ans.back() == '0'){
		ans.pop_back();
	}
	
	// Reverse to get the smallest number
	reverse(ans.begin(), ans.end());

	// In some cases, ans will be empty such as:
	// Ex: num = "9", k=1;  num = "45213" k = 5
	return ans.empty()  ? "0" : ans;
}
};