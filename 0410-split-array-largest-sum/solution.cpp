class Solution {
public:
    long long largestsum(vector<int> &nums){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(long long)nums[i];
        }
        return sum;
    }

    bool minimizedlargestsum(vector<int> &nums,int k,long long mid){
        int countsubarray=1;
        long long sumofsubarray=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return false;
            if(sumofsubarray+nums[i]<=mid){
                sumofsubarray+=nums[i];
            }else{
                countsubarray++;
                sumofsubarray=nums[i];
            }
        }
        
        if(countsubarray<=k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
       
        long long low=*max_element(nums.begin(),nums.end());
        long long high=largestsum(nums); 
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;

            bool possible=minimizedlargestsum(nums,k,mid);
            if(possible){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
