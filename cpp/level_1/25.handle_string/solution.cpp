#include <string>
#include <cctype>
#include <iostream>

using namespace std;

bool solution(string s)
{
    if (s.size() ^ 4 && s.size() ^ 6)
        return false;

    for (const char &c : s)
        if (!isdigit(tolower(c)))
            return false;
    return true;
}

int main()
{
    bool answer = solution("1234");
    cout << answer << endl;

    if (8)
        cout << "asdasd" << endl;
    return 0;
}