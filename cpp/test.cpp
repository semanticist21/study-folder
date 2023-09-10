#include <vector>
#include <iostream>

namespace A_RANGE
{
    int score = 100;
    int FUNC(int s)
    {
        return s / 5;
    }
}

namespace B_RANGE
{
    int score = 200;
    int FUNC(int s)
    {
        return s / 10;
    }
}

using namespace std;
using namespace A_RANGE;
using namespace B_RANGE;

int main()
{
    int score = 300;

    vector<int> v(200000000);

    int val = 0;
    for (const int &i : v)
    {
        // cout << val;
        // ++val;
    }

    cout << "main score : " << score << endl;
    cout << "A_RANGE score : " << A_RANGE::score << endl;
    cout << "B_RANGE score : " << B_RANGE::score << endl;

    return 0;
}