class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int r=0,l=0;
        int maxlen=0;
        int hash[256];
        fill(hash,hash+256,-1);
        while(r<s.size()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                } 
            }
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;
            
        }
    return maxlen;
    }
};
