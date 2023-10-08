#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answers;

    for (const int &i : arr)
        if (!(i % divisor))
            answers.emplace_back(i);

    sort(answers.begin(), answers.end());

    return answers.size() ? answers : vector<int>(1, -1);
}

int main()
{
    vector<int> arr = {5, 9, 7, 10};
    auto rs = solution(arr, 5);

    for (const int &n : rs)
        cout << n << endl;
    return 0;
}