#include <iostream>

using namespace std;

long long solution(int a, int b)
{
    long long answer = 0;

    // XOR swap algorhtm;
    if (a > b)
        a ^= b ^= a ^= b;

    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
    return answer;
}

int main()
{
    long long answer = solution(3, 5);
    cout << answer << endl;
    return 0;
}