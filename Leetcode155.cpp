class MinStack {
    stack<int> min;
    stack<int> prime;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        prime.push(val);
        if(min.empty() || val<=min.top()){
            min.push(val);
        }
    }
    
    void pop() {
        if(min.top() == prime.top()){
            min.pop();
        }
        prime.pop();
    }
    
    int top() {
        return prime.top();
    }
    
    int getMin() {
        return min.top();
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
