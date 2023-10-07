// 에스토스테네스의 체 활용

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{

    int sqrted = floor(sqrt(n));
    vector<int> filter;

    for (int i = 2; i <= sqrted; ++i)
    {
        bool is_prime = true;
        for (int &f : filter)
        {
            if (i % f == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            filter.emplace_back(i);
    }

    vector<int> v(n, 0);
    for (int i = 1; i < n; i++)
        v[i] = i + 1;

    for (int &n : v)
        for (int &f : filter)
            if (n != 0 && n % f == 0)
            {
                n = 0;
                break;
            }

    int total = 0;
    for (const int &n : v)
        if (n != 0)
            ++total;

    return total + filter.size();
}

int main()
{
    auto rs = solution(1000000);
    cout << rs << endl;

    return 0;
}
