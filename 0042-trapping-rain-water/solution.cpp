class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0,rmax=0,totalwater=0,l=0,r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    totalwater+=lmax-height[l];
                    l++;
                }else{
                    lmax=height[l];
                    l++;
                }
            }else{
                if(rmax>height[r]){
                    totalwater+=rmax-height[r];
                    r--;
                }else{
                    rmax=height[r];
                    r--;
                }
            }
        }
    return totalwater;       
    }
};
