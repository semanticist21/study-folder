#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int k)
{
    // to digit
    vector<int> k_digit;

    int at = 0;
    int c = n;

    while (c)
    {
        int q = c / k;
        int r = c % k;

        c = q;
        k_digit.emplace_back(r);
    }

    reverse(k_digit.begin(), k_digit.end());

    // P
    // P0
    // 0P
    // 0P0
}

int main()
{
    solution(10, 2);
    return 0;
}