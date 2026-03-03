class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_to_t;
        unordered_map<char,char> t_to_s;

        int i=0;
        while( i<s.size() && i<t.size() ){
            
            if(s_to_t.find(s[i])!=s_to_t.end()){
                
                if(s_to_t[s[i]]!=t[i]) return false;
                else{
                    i++;
                    continue;
                }
            }
            s_to_t[s[i]]=t[i];
            i++;
        }
        int j=0;
        while( j<s.size() && j<t.size() ){
            
            if(t_to_s.find(t[j])!=t_to_s.end()){
                
                if(t_to_s[t[j]]!=s[j]) return false;
                else{
                    j++;
                    continue;
                }
            }
            t_to_s[t[j]]=s[j];
            j++;
        }
    return true;
    }
};
