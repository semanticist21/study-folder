#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        int row = i / n;
        int ord = i % n;

        if (row >= ord)
            answer.emplace_back(row + 1);
        else
            answer.emplace_back(ord + 1);
    }

    return answer;
}

int main()
{
    auto rs = solution(3, 2, 5);

    for (const int &i : rs)
        cout << i << endl;

    return 0;
}