#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x)
{
    int cnt = 0;
    for (const char &c : to_string(x))
        cnt += c - '0';

    return x % cnt == 0;
}

int main()
{
    auto rs = solution(11);
    cout << rs << endl;
    return 0;
}