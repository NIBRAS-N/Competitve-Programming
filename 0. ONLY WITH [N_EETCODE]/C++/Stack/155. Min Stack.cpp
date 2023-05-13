/*
    Design stack that supports push, pop, top, & retriving min element
     Time: O(1)
    Space: O(n)
*/


class MinStack {
public:
  
  
    stack<int>abc;
    stack<int>mn;
    long long int kk = __INT32_MAX__;
    MinStack() {
        
    }
    
    void push(int val) {
        abc.push(val);
        if(mn.empty() || val<=mn.top()){
            
            mn.push(val);
            
        }
        
    }
    
    void pop() {
        if(mn.top()==abc.top() && !mn.empty()&& !abc.empty()){
            mn.pop();
            
        }
        
            abc.pop();
        
    }
    
    int top() {
        return abc.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

