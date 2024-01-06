#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string myString)
{
    ostringstream oss;

    for (const char &c : myString)
        oss << static_cast<char>(tolower(c));

    return oss.str();
}

int main()
{
    string rs = solution("abcdDEFG");

    cout << rs << endl;
    return 0;
}