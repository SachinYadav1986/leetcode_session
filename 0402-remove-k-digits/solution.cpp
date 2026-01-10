class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        stack<char> st;
        int j=k;
        int i=0;
    while(i<num.size()){
            while(!st.empty() && j>0 && (num[i]-'0'<st.top()-'0')){
                st.pop();
                j--;
            }
            if(st.empty() && num[i]=='0'){
                i++;
                continue;
            }
            st.push(num[i]);
            i++;
    }
while(!st.empty() && j>0){
                st.pop();
                j--;
            }
            if(st.empty()) return "0";
            string ans="";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};
