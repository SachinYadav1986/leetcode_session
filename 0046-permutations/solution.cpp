class Solution {
public:
    int fact(int size){
        if(size==0 || size==1) return 1;
        return fact(size-1)*size;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(nums);
        int size=nums.size();
        int length=fact(size);
        for(int x=0;x<length-1;x++){
            next_permutation(nums.begin(),nums.end());
            ans.push_back(nums);
            
        }

        return ans;

    }
};
