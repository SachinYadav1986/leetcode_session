class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {
       stack<int> st;
       int n=num.size();
       vector<int> nge(n);
       
       for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=num[i%n]) st.pop();
        
        if(i<n){
            nge[i]=st.empty()?-1:st.top();
        }
        
        st.push(num[i%n]);
        }
         
        return nge;       
    }
};
