class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,med=0,high=nums.size()-1;
        while(med<=high){
            if(nums[med]==2){
                swap(nums[med],nums[high]);
                high--;
                
            }
            else if(nums[med]==1){
                med++;
            }
            else{
                swap(nums[low],nums[med]);
                low++;
                med++;
            }
        }
        
    }
};
