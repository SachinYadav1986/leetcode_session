class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows=matrix.size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                if(j<=i) continue;
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<rows;i++){
            int left=0;
            int right=rows-1;
            while(left<right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }
        }

    }
};
