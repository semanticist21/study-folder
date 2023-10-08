#include <iostream>

using namespace std;

int solution(int num)
{
    int cycle = 0;
    long long l = num;

    while (cycle < 500 && l != 1)
    {
        l = l & 1 ? l + (l << 1) + 1 : l >> 1;
        cycle++;
    }

    return cycle == 500 ? -1 : cycle;
}

int main()
{
    int answer = solution(626331);
    cout << answer << endl;
    return 0;
}