#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++)
    {
        vector<int> row(n);
        matrix.emplace_back(row);
    }

    int cur = 1;
    int row = 0;
    int col = 0;
    int iter = pow(n, 2);

    int offset = 0;

    while (true)
    {
        matrix[row][col] = cur;

        if (cur == n - 1)
            break;

        if (row == offset && col < n - 1 - offset)
            col++;
        else if (row < n - 1 - offset && col == n - 1 - offset)
            row++;
        else if (col > offset && row == n - 1 - offset)
        {
            col--;
            offset++;
        }
        else if (col == offset - 1 && row > offset)
            row--;

        cur++;
    }

    return matrix;
}

int main()
{
    solution(3);
    return 0;
}