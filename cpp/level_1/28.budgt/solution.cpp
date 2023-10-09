#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    sort(d.begin(), d.end());

    int i = 0;
    while (budget >= 0 && i < d.size())
    {
        if (budget - d[i] >= 0)
            budget -= d[i];
        else
            break;
        ++i;
    }

    return i;
}

int main()
{
    vector<int> d = {1, 3, 2, 5, 4};
    int budget = 9;

    solution(d, budget);
    return 0;
}