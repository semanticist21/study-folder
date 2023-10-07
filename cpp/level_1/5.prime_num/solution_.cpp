// 에스토스테네스의 체 활용

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<bool> tmp(n + 1, true);

    for (int i = 2; i < n + 1; i++)
    {
        if (tmp[i])
        {
            for (int j = 2; i * j < n + 1; j++)
                tmp[i * j] = false;
            answer++;
        }
    }

    return answer;
}

int main()
{
    auto rs = solution(1000000);
    cout << rs << endl;

    return 0;
}
