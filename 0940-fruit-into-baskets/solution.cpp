class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> mpp;
        int maxlen=0;
        int l=0,r=0;
        for(int r=0;r<fruits.size();r++){
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            maxlen=max(r-l+1,maxlen);
        }
        return maxlen;
    }
};
