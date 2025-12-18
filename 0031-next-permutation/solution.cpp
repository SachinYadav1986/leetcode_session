class Solution {
public:
    int breakexist(vector<int> &nums){
            int size=nums.size();
            int index=-1;
            for(int i=size-1;i>0;i--){
                if(nums[i-1]<nums[i]){
                index=i-1;
                break;
                }
            }
        return index;
        }
    vector<int> nextPermutation(vector<int>& nums){
        int size=nums.size();
        if(size==1 ||  size==0) return nums;
        int index=breakexist(nums);
        if(index==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=size-1;i>index;i--){
                if(nums[index]<nums[i]){
                swap(nums[index],nums[i]);
                break;
                }
            }
            reverse(nums.begin()+index+1,nums.end());
        }
        return nums;
    }    
    
};
