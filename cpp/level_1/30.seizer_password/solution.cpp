#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// working on
string solution(string s, int n)
{
    for (char &c : s)
    {
        int r = c + n;
        if (isspace(c))
            continue;
        else if (isupper(c))
        {
            if (r > 'Z')
                r -= 26;
        }
        else
        {
            if (r > 'z')
                r -= 26;
        }
        c = r;
    }

    return s;
}

int main()
{
    auto rs = solution("fghizk", 25);
    cout << rs << endl;
    return 0;
}