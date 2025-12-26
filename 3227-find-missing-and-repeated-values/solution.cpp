class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int xr=0;
        for(int i=1;i<=rows*cols;i++){
            xr=xr^i;
        }
        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            xr=xr^grid[i][j];
        }
        }
        int number=xr & ~(xr-1);
        int one=0;
        int zero=0;
        for(int i=1;i<=rows*cols;i++){
            if((i & number)!=0){
                one=one^i;
            }
            else{
                zero=zero^i;
            }
        }
        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if((grid[i][j] & number)!=0){
                one=one^grid[i][j];
            }
            else{
                zero=zero^grid[i][j];
            }
        }
        }
        int count1=0;
        int count2=0;
        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(one==grid[i][j]){
                count1++;
            }
            if(zero==grid[i][j]){
                count2++;
            }
        }
        }
        if(count1==2) return {one,zero};
        else return {zero,one};
    }
};
