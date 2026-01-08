class MinStack {
public:
    stack<long long> st;
    long long minn;
    MinStack() {
        
    }
    
    void push(int val) {
        long long x=val;
        if(st.empty()){
            st.push(x);
            minn=x;
            return;
        }else{
            if(val>=minn) st.push(x);
            else{
                st.push(2*x-minn);
                minn=x;
            }
        }    
    }
    
    void pop() {
        if(st.empty()) return;
        long long n=st.top();
        st.pop();
        if(n<minn){
        minn=2*minn-n;
        }    
    }
    
    int top() {
        long long x=st.top();
        if(minn>x){
            return minn;
        }else{
            return x;
        }
    }
    
    int getMin() {
        return minn;
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
