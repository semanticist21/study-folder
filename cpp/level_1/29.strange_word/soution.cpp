#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s)
{
    int cnt = 1;
    for (char &c : s)
        if (c ^ 32)
            cnt++ && (cnt & 1) ? c = tolower(c) : c = toupper(c);
        else
            cnt = 1;

    return s;
}

int main()
{
    cout << solution("try hello world") << endl;
    return 0;
}