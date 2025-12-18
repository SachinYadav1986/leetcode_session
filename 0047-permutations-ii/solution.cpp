class Solution {
public:
    int fact(int size){
        if(size==0 || size==1) return 1;
        return fact(size-1)*size;
    }
    vector<vector<int>>  permuteUnique(vector<int>& nums) {
        set<vector<int>> unique;
        unique.insert(nums);
        int size=nums.size();
        int length=fact(size);
        for(int x=0;x<length-1;x++){
            next_permutation(nums.begin(),nums.end());
            unique.insert(nums);
            
        }
        vector<vector<int>> ans(unique.begin(), unique.end());


        return ans;

    }
};
