class Solution {
public:
    int maxDepth(string s) {
        int max_depth=0;
        int count=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                count++;
            }
            if(s[i]==')'){
                count--;
            }
            max_depth=max(max_depth,count);
            i++;
        }
        return max_depth;
    }
};
