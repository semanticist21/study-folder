#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(int n)
{
    vector<string> v(n);

    for (int i = 0; i < n; i++)
        i & 1 ? v.emplace_back("박") : v.emplace_back("수");

    ostringstream os;

    for (const string &str : v)
        os << str;

    return os.str();
}

int main()
{
    string rs = solution(5);
    cout << rs << endl;
    return 0;
}