class Solution {
public:
    int find_Maximum_In_column(vector<vector<int>>& mat,int column){
        int maxelement=INT_MIN;
        int rowindex=-1;
        int rows=mat.size();
        for(int i=0;i<rows;i++){
            if(mat[i][column]>maxelement){
                maxelement=mat[i][column];
                rowindex=i;
            }

        }
        return rowindex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int n=cols-1;
        
        int low=0,high=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            int rowindex=find_Maximum_In_column(mat,mid);
            int left=mid-1>=0 ? mat[rowindex][mid-1] : -1;
            int right=mid+1<=n ? mat[rowindex][mid+1] : -1;
            if(mat[rowindex][mid]>left && mat[rowindex][mid]>right) return {rowindex,mid};
            if(mat[rowindex][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
    return {-1,-1};
    }
};
