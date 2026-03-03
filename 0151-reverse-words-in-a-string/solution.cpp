class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string ans;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ' && st.empty()) continue;
            else if(s[i]==' ' && !st.empty()){
                while(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                    }
                    ans.push_back(' ');
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            }
        if(ans.back()==' '){
            ans.pop_back();
        }
    return ans;
    }
};
