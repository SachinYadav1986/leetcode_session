class Solution {
public:
    int upper_bound(vector<int> &nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ub=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ub=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ub;
    }
    int lower_bound(vector<int> &nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int lb=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                lb=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return lb;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower_bound(nums,target);
        if(lb==nums.size() || nums[lb]!=target) return {-1,-1};
        return {lb,upper_bound(nums,target)-1};
    }
};
