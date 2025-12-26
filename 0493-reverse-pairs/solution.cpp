class Solution {
public:
    void merging(vector<int> &nums,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        
    }
    int countpairs(vector<int> &nums,int low,int mid,int high){
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>2*(long long)nums[right]) right++;
            count+=right-(mid+1);
        }
        return count;
    }
    int mergesort(vector<int> &nums,int low,int high){
        int count=0;
        if(low>=high)  return count;
        int mid=(low+high)/2;

        count+=mergesort(nums,low,mid);
        count+=mergesort(nums,mid+1,high);
        count+=countpairs(nums,low,mid,high);
        merging(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums){
        int low=0;
        int high=nums.size()-1;
        return mergesort(nums,low,high);
        
    }
};
