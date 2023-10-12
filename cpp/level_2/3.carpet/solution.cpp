#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int limit = brown + yellow;

    for (int i = 3; i <= limit / 3; i++)
        for (int j = 3; j <= i; j++)
            if (i * j == limit)
            {

                bool is_set = false;

                int temp_j = j;
                int temp_i = i;
                while (true)
                {
                    int border = temp_i * 2 + 2 * (temp_j - 2);
                    int remnant = temp_i * temp_j - border;

                    if (remnant == yellow)
                    {
                        is_set = true;
                        break;
                    }

                    temp_i--;
                    temp_j--;

                    if (temp_i <= 2 || temp_j <= 0)
                    {
                        break;
                    }
                }

                if (!is_set)
                    continue;

                return {i, j};
            }

    return {0, 0};
}

int main()
{
    auto rs = solution(18, 6);
    cout << rs[0] << endl;
    cout << rs[1] << endl;
    return 0;
}