class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
     
     int ans=0;
     for(int i=0;i<board.size();i++)
     {   int count=0;
         for(int j=0;j<board[0].size();j++)
         {
             if(board[i][j]=='X')
             {
                if(i-1>=0 && board[i-1][j]=='X' || (j-1)>=0 && board[i][j-1]=='X')
                {

                }
                else {
                    ans++;
                }
             }
         }
         
     }   
     return ans;
    }
};