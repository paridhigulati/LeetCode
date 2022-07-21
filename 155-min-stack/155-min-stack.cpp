class MinStack {
public:
    
    stack<int>st;
    stack<int>mini;
    
    MinStack() {
        
    }
    
    void push(int val) {
        //keep track of min also 
        if(mini.empty() || getMin() >= val) mini.push(val);
     st.push(val);   
    }
    
    void pop() {
        if(top() == getMin()) mini.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */