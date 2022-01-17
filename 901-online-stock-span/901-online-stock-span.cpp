class StockSpanner {
public:
    //next greater on left 
    stack<pair<int,int>>st;
    StockSpanner() {
  
        
    }
    
    int next(int price) {
        int cnt = 1;
        		 // if element is greater than equal to price of top of stack then its count will be equal to (1 + cnt of stack top element)

        while(!st.empty() and st.top().first <= price )
        {
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return st.top().second;
    }
        
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */