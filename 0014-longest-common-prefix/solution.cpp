class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string comp=strs[0];
        if(comp.empty()) return "";
        int i=1;
        while(i<=strs.size()-1){
            string temp=strs[i];
            int j=0;
            while(j<=temp.size()-1 && j<=comp.size()-1){
                if(temp[j]!=comp[j] && j==0){
                    return "";
                }
                if(temp[j]!=comp[j]){ 
                    break;
                }
                j++;
            }
            comp=comp.substr(0,j);
            i++;
        }
        return comp;
    }
};
