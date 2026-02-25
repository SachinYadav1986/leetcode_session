class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count=0;
        int i=0;
        
        while(i<s.size()){
            if(s[i]=='(' && count!=0){
                count++;
                ans.push_back(s[i]);
            }
            else if(s[i]==')'){
                count--;
                if(count!=0){
                    ans.push_back(s[i]);
                }
            }else{
                count++;
            }    
        i++;
        }
    return ans;
    }
    
};
