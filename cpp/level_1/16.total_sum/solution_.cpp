#include <iostream>

using namespace std;

long long solution(int a, int b)
{
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}

int main()
{
    long long answer = solution(3, 5);
    cout << answer << endl;
    return 0;
}