class Solution {
public:
vector<int>generatingrow(int row){
    vector<int> generaterow;
        long long ans=1;
        generaterow.push_back(ans);
        for(int cols=1;cols<row;cols++){
            ans=ans*(row-cols);
            ans=ans/cols;
            generaterow.push_back(ans);
        }
        return generaterow;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1;row<=numRows;row++){
            ans.push_back(generatingrow(row));

        }
        return ans;
        
    }
};
