#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int k)
{
    return numbers[((k - 1) * 2) % numbers.size()];
}

int main()
{
    vector<int> s = {1, 2, 3, 4};
    int k = 2;

    int r = solution(s, k);
    cout << r << endl;
    return 0;
}