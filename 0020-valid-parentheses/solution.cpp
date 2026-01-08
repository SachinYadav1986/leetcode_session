class Solution {
public:
    bool isValid(string s) {
    stack<int> st;
    for(auto c:s){
        if((c=='(')|| (c=='[') || (c=='{')) st.push(c);
        else{
            if(st.empty()) return false;
            if((st.top()=='(' && c==')') || (st.top()=='[' && c==']') || (st.top()=='{' && c=='}')) st.pop();
            else{
                return false;
            }
            }  
        }
    return st.empty();
    }
};
