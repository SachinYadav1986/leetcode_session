class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        if( s.size()==0 || s.size()==1) return sum;
        for(int i=0;i<s.size()-2;i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                int largest=INT_MIN;
                int smallest=INT_MAX;
                for(auto it:mpp){
                    if(it.second>largest){
                        largest=it.second;
                    }
                    if(it.second<smallest){
                    smallest=it.second;
                    }
                    
                }
                sum+=largest-smallest;
            }
            
            
        }
        return sum;
    }
};
