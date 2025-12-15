class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate=0;
        int count=0;

        for(int i=0;i<nums.size();i++){   //candidate selection if appears more than n/2 times
            if(count==0){
                candidate=nums[i];
                count++;
            }else if(candidate==nums[i]){
                count++;
            }else{
                count--;
            }
        }

        count=0;
        int threshold=nums.size()/2;
        for(auto it:nums){
            if(candidate==it) count++;
            
        }
    return(count>threshold)? candidate:-1;

    }
  
};
