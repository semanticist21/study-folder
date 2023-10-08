#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int p = 0;
    int y = 0;

    for (const char &c : s)
        tolower(c) == 'p' ? ++p : tolower(c) == 'y' ? ++y
                                                    : 0;

    return p == y;
}

int main()
{
    bool rs = solution("pPoooyY");
    cout << rs << endl;
    return 0;
}