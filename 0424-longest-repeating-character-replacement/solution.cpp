class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mpp(26,0);
        int l=0,r=0;
        int maxlen=0;
        int maxfreq=0;
        while(r<s.size()){
            mpp[s[r]-'A']++;
            maxfreq=max(maxfreq,mpp[s[r]-'A']);
            
            while((r-l+1)-maxfreq>k){
                mpp[s[l]-'A']--;
                l++;
                continue;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen; 
    }
};
