class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> prefixsum(rows, vector<int>(cols));
        for(int i=0;i<cols;i++){
            int prevsum=0;
            for(int j=0;j<rows;j++){
                prevsum=(matrix[j][i]=='1')?prevsum+1:0;
                prefixsum[j][i]=prevsum;
            }
        }

        int maxarea=0;
        
        for(int i=0;i<rows;i++){
            stack<int> st;
            for(int j=0;j<cols;j++){
                while(!st.empty() && prefixsum[i][st.top()]>prefixsum[i][j]){
                    int element=st.top();
                    st.pop();
                    int pse=st.empty()?-1:st.top();
                    int nse=j;
                    maxarea=max(maxarea,prefixsum[i][element]*(nse-pse-1));
                }
            st.push(j);
            }
            while(!st.empty()){
                int element=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=prefixsum[0].size();
                maxarea=max(maxarea,prefixsum[i][element]*(nse-pse-1));
        }
        }
    return maxarea;
    }
};
