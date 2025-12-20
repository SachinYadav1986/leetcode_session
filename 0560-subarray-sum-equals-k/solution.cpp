class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int sum=0;
        int rem=0;
        int count=0;
        map<int,int> mpp;
        mpp[0]=1;
        int i=0;
        while(i<nums.size()){
            sum+=nums[i];
            rem=sum-k;
            count+=mpp[rem];
            mpp[sum]+=1;
            i++;
        }
        return count;
    }
        
    
};

