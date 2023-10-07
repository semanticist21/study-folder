#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    vector<int> dolls;
    int total = 0;

    for (const int &move : moves)
        for (vector<int> &line : board)
            if (line[move - 1] != 0)
            {
                int *doll = &line[move - 1];
                if (!dolls.empty() && dolls.back() == *doll)
                {
                    dolls.pop_back();
                    total += 2;
                }
                else
                {
                    dolls.emplace_back(*doll);
                }

                *doll = 0;
                break;
            }

    return total;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};

    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    auto rs = solution(board, moves);
    cout << rs << endl;

    return 0;
}