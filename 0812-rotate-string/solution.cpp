class Solution {
public:
    bool rotateString(string s, string goal) {
        int i=0;
        string res=s;
        while(i<s.size()){
            res=res.substr(1,res.size()-1)+res[0];
            if(res==goal) return true;
            i++;
        }
        return false;
    }
};
