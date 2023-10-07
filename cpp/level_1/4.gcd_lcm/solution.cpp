#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

vector<int> solution(int a, int b)
{
    int gcd_n = gcd(a, b);
    int lcm_n = lcm(a, b);

    vector<int> answer(2, gcd_n);
    answer[1] = lcm_n;

    return answer;
}


int main()
{
    return 0;
}