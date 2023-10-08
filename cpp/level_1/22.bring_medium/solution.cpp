#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s)
{
    return s.size() & 1 ? string(1, s[s.size() / 2]) : s.substr(s.size() / 2 - 1, 2);
}

int main()
{
    auto rs = solution("abcde");
    cout << rs << endl;

    auto rs_ = solution("qwer");
    cout << rs_ << endl;
    return 0;
}