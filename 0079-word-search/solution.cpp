class Solution {
public:
     void check(int row,int col,int i,bool &s,vector<vector<char>>& board,string &word){
        if(s) return;
        if(board[row][col]!=word[i]) return;
        if(i==word.size()-1){
            s=true;
            return;
        }
        

        char temp=board[row][col];
        board[row][col]='*'; //marking visited cell

        if(col>0){
            check(row,col-1,i+1,s,board,word);
        } //go up

        if(row>0){
            check(row-1,col,i+1,s,board,word);
        } //go left

        if(col<board[0].size()-1){
            check(row,col+1,i+1,s,board,word);
        } // go right

        if(row<board.size()-1){
            check(row+1,col,i+1,s,board,word);
        } // go down

        board[row][col]=temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool s=false;
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                check(row,col,0,s,board,word);
                if(s) return true;
            }
        }
        return s;
        
    }
};
