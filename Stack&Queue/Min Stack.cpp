class MinStack {
    long long min_elem;
    stack<long long> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            min_elem=val;
        }else{
            if(val>=min_elem){
                s.push(val);
            }else{
                s.push(2ll*val-min_elem);
                min_elem=val;
            }
        }
        return;
    }
    
    void pop() {
        if(s.top()<min_elem){
            min_elem=2ll*min_elem-s.top();
        }
        s.pop();
        return;
    }
    
    int top() {
        if(s.top()<min_elem){
            return min_elem;
        }
        return s.top();
    }
    
    int getMin() {
        return min_elem;
    }
};