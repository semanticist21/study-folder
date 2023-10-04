#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> v(n, x);

    for (int i = 1; i < n; i++)
        v[i] = v[i - 1] + x;

    return v;
}

int main()
{
    auto rs = solution(2, 5);

    for (const auto &i : rs)
    {
        cout << i << endl;
    }

    return 0;
}