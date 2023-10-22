#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] != 1) continue;

            if(i-1 >= 0 && board[i-1][j] != 1) board[i-1][j] = 2;
            if(i+1 < board.size() && board[i+1][j] != 1) board[i+1][j] = 2;
            if(j-1 >= 0 && board[i][j-1] != 1) board[i][j-1] = 2;
            if(j+1 < board[0].size() && board[i][j+1] != 1) board[i][j+1] = 2;
            if(i-1 >= 0 && j-1 >=0 && board[i-1][j-1] != 1) board[i-1][j-1] = 2;
            if(i+1 < board.size() && j+1 < board[0].size() && board[i+1][j+1] != 1) board[i+1][j+1] = 2;
            if(i+1 < board.size() && j-1 >= 0 && board[i+1][j-1] != 1) board[i+1][j-1] = 2;
            if(i-1 >= 0 && j+1 < board[0].size() && board[i-1][j+1] != 1) board[i-1][j+1] = 2;
        }

    int total = 0;

    for(const vector<int> &v: board)
        for(const int &i : v)
            if(i==0) total++;

    return total;
}

int main()
{
    return 0;
}