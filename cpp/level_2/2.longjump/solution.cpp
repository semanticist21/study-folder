#include <iostream>
#include <vector>

using namespace std;

long long solution(int n)
{
    vector<int> v(n, 0);
    v[0] = 1;
    v[1] = 2;

    for (int i = 0; i < v.size(); ++i)
        if (v[i] == 0) v[i] = (v[i - 1] + v[i - 2]) % 1234567;

    return v.back();
}

int main()
{
    auto rs = solution(55);
    cout << rs << endl;

    return 0;
}