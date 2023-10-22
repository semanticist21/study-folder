#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int solution(int a, int b)
{
    int gcd_num = gcd(a, b);
    int reduced_fraction = (b / gcd_num);

    vector<int> divides;

    for (int i = 0; pow(2, i) <= reduced_fraction; i++)
        for (int j = 0; pow(5, j) <= reduced_fraction; j++)
            if (round(pow(2, i)) * round(pow(5, j)) <= reduced_fraction)
                divides.emplace_back(round(pow(2, i)) * round(pow(5, j)));

    bool has_impurity = false;
    for (int i = 3; i <= reduced_fraction; i++)
        if (reduced_fraction % i == 0 && find(divides.begin(), divides.end(), i) == divides.end())
            has_impurity = true;

    return has_impurity ? 2 : 1;
}

int main()
{
    return 0;
}