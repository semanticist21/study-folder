#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// working on
string solution(string s, int n)
{
    for (char &c : s)
        if (!(c ^ ' '))
            continue;
        else if (!isalpha(c + n))
            c -= 'z' - 'a' - n + 1;
        else
            c += n;

    return s;
}

int main()
{
    auto rs = solution("ZZ   aK", 25);
    cout << rs << endl;
    return 0;
}