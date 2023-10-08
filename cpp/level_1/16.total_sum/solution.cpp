#include <iostream>

using namespace std;

long long solution(int a, int b)
{
    return ((static_cast<double>(a) + static_cast<double>(b)) / 2) * (abs(a - b) + 1);
}

int main()
{
    long long answer = solution(3, 5);
    cout << answer << endl;
    return 0;
}