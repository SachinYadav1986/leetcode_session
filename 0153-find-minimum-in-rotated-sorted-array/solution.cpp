class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int minn=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[high]){
                minn=min(nums[low],minn);
            }
            if(nums[low]<=nums[mid]){
                minn=min(nums[low],minn);
                low=mid+1;
            }
            else{
                minn=min(nums[mid],minn);
                high=mid-1;
            }
        }
    return minn;
    }
};
