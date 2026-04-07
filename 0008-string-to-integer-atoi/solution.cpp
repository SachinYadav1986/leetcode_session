class Solution {
public:
    int myAtoi(string s) {
        int res=0;
        int sign=1;
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(i<s.size() &&(s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        while(i<s.size() && isdigit(s[i])){
            int temp=s[i]-'0';
            if(res>(INT_MAX-temp)/10){
                return sign==1?INT_MAX:INT_MIN;
            }
            res=res*10+temp;
            i++;
        }
        return sign*res;
    }
};
