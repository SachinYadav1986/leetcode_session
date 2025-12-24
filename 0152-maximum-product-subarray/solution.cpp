class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int start=1;
        int last=1;
        int maxxproduct1=INT_MIN,maxxproduct2=INT_MIN;
        for(int i=0;i<n;i++){
            start*=nums[i];
            if(start==0){
                maxxproduct1=max(maxxproduct1,start);
                start=1;
                continue;
            }
            
            maxxproduct1=max(maxxproduct1,start);
        }
        for(int i=n-1;i>=0;i--){
            last*=nums[i];
            if(last==0){
                maxxproduct2=max(maxxproduct2,last);
                last=1;
                continue;
            }
            
            maxxproduct2=max(maxxproduct2,last);
        }
        int maxxproduct=max(maxxproduct1,maxxproduct2);
        return maxxproduct;
    }
};
