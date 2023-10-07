#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> find_position(vector<string> board, char find)
{
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; i < board[i].size(); j++)
            if (board[i][j] == find)
                return make_pair(j, i);

    return make_pair(-1, -1);
};

vector<pair<int, int>> move(vector<string> board, vector<pair<int, int>> moves)
{
    pair<int, int> target = find_position(board, 'G');
    pair<int, int> self = moves.back();

    int left = -1;
    int right = board[0].size();
    int top = -1;
    int bottom = board.size();

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; i < board[i].size(); j++)
            if (board[i][j] == 'D')
            {
                bool is_at_x = j == self.first;
                bool is_at_y = i == self.second;

                if (is_at_x && i > self.second && i < bottom)
                    bottom = i;
                if (is_at_x && i < self.second && i > top)
                    top = i;
                if (is_at_y && j > self.first && j > left)
                    left = j;
                if (is_at_y && j < self.first && j < left)
                    right = j;
            }
}

int solution(vector<string> board)
{
    pair<int, int> target = find_position(board, 'G');

    return 1;
}

int main()
{
    // vector<string> data = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
    // auto rs = solution(data);

    // cout << rs << endl;
    return 0;
}