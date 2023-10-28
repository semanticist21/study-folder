#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    vector<int> memoized(4, 0);
    vector<int> temp(4, 0);

    for (const auto &l : land)
    {
        for (int i = 0; i < 4; i++)
        {
            int max = 0x80000000;
            for (int j = 0; j < 4; j++)
                if (j != i && temp[j] > max)
                    max = temp[j];

            memoized[i] = l[i] + max;
        }
        temp = memoized;
    }

    return *max_element(memoized.begin(), memoized.end());
}

int main()
{
    vector<vector<int>> test = {{1, 2, 3, 5},
                                {5, 6, 7, 8},
                                {4, 3, 2, 1}};
    auto rs = solution(test);
    cout << rs << endl;

    return 0;
}