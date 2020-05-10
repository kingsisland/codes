#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector< unordered_set<char> > row_set;
    vector< unordered_set<char> > col_set;
    unordered_map<string, unordered_set<char> > nonet;

    bool solve(int i, int j, vector<vector<char>>& board)
    {   //cout<<"Solve ("<<i<<","<<j<<")\n";
        int row = i, col = j;
        for( ; row<9; row++)
        {
           for(; col<9; col++)
           {
               if(board[row][col] != '.')
               {   //cout<<"num found at ("<<row<<","<<col<<")\n";
                   if(row == 8 && col == 8)
                       return true;
                   continue;
               }
               
               string key = to_string((int)row/3) + to_string((int)col/3);
               for(char num = '1'; num <= '9'; num++)
               {   
                    
                   if( row_set[row].find(num) != row_set[row].end() || col_set[col].find(num) 
                            != col_set[col].end() || nonet[key].find(num) != nonet[key].end() )
                                continue;
                   
                   board[row][col] = num;
                   row_set[row].insert(num);
                   col_set[col].insert(num);
                   unordered_set<char> temp = nonet[key];
                   temp.insert(num);
                   nonet[key] = temp;
                   
                   if(row == 8 && col == 8)
                       return true;
                   
                   //cout<<"num : "<<num<<"  & Calling solve in ("<<row<<","<<col<<")\n";
                   if(solve(row, col+1, board))
                       return true;
                   // if num doesnt fit:
                   board[row][col] = '.';
                   row_set[row].erase(num);
                   col_set[col].erase(num);
                   temp = nonet[key];
                   temp.erase(num);
                   nonet[key] = temp;
                   
                       
               }
               //cout<<"fault occurred at ("<<row<<","<<col<<")\n";
                return false;   
           }
           col =0;
        }
        return false;
    }
public:
    Solution()
    {
        row_set = vector< unordered_set<char> >(9, unordered_set<char>() );
        col_set = vector< unordered_set<char> >(9, unordered_set<char>() );
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        //////////////////////////////////////////////
        // for(int row = 0; row<9; row++)
        // {
        //    for(int col = 0; col<9; col++)
        //    {
               
        //        cout<<board[row][col]<<" ";
        //    }
        //    cout<<endl;
        // }
        /////////////////////////////////////////////

        for(int i =0; i<3; i++)
        {
            for(int j =0; j<3; j++)
            {
                string key = to_string(i) + to_string(j);
                nonet[key] = unordered_set<char>();
            }
        }
        // Fill the row, col and nonet sets
        for(int row = 0; row<9; row++)
        {
            for(int col = 0; col <9; col++)
            {
                if(board[row][col] == '.')
                    continue;
                row_set[row].insert(board[row][col]);
                col_set[col].insert(board[row][col]);
                string key = to_string((int)row/3) + to_string((int)col/3);
               
                unordered_set<char> temp = nonet[key];
                temp.insert(board[row][col]);
                nonet[key] = temp;
            }
        }

        // if(solve(0, 0 , board)) cout<<"Done\n";

        // for(int row = 0; row<9; row++)
        // {
        //    for(int col = 0; col<9; col++)
        //    {
               
        //        cout<<board[row][col]<<" ";
        //    }
        //    cout<<endl;
        // }

        solve(0, 0 , board);
        return;
        
    }
};

int main()
{
    Solution solution = Solution();
    vector<vector<char>> board {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},
                                        {'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
                                            {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},
                                                {'.','.','.','.','8','.','.','7','9'}};

    //vector<vector<char>> board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]];
    solution.solveSudoku(board);
    return 0 ;
}
