class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //maximum element can be 2 greator then n/3 times
        int count1=0,count2=0;
        int candidate1=INT_MIN,candidate2=INT_MIN;
        
        

        for(int i=0;i<nums.size();i++){ //selection of candidate
            if(count1==0 && nums[i]!=candidate2){
                candidate1=nums[i];
                count1++;}
            else if(count2==0 && nums[i]!=candidate1){
                candidate2=nums[i];
                count2++;}

            else if(candidate1==nums[i]){
                count1++;}
            else if(candidate2==nums[i]){
                count2++;}

            else{
            count1--;
            count2--;}
            }

    
    count1=0;
    count2=0;
    int threshold=nums.size()/3+1;
    vector<int> ans;
    for(auto it:nums){
        if(candidate1==it){
            count1++;
        }
        else if(candidate2==it){
            count2++;
        }
    }
    if(count1>=threshold){
        ans.push_back(candidate1);
    }
    if(count2>=threshold){
        ans.push_back(candidate2);
    }
    
    return ans;
    }
    
};
