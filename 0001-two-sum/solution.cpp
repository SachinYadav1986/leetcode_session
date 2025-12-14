class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int value=0;
        map<int,int>mpp;
        int i;
        for(i=0;i<nums.size();i++){
            value=nums[i];
        
        int rem=target-value;
        if(mpp.find(rem)!=mpp.end()){
            
            return {mpp[rem],i};
            
        }
        mpp[value]=i;
        }
      return {-1,-1};  
    }
    
};
