#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
    int mode = 0;
    vector<char> str;

    for (int i = 0; i < code.size(); i++)
    {
        char c = code[i];

        if (mode == 1 && c == '1')
            mode = 0;
        else if (mode == 0 && c == '1')
            mode = 1;
        else if (mode == 0 && !(i & 1))
            str.emplace_back(c);
        else if (mode == 1 && (i & 1))
            str.emplace_back(c);
    }

    string rs = string(str.begin(), str.end());

    return rs.size() ? rs : "EMPTY";
}

int main()
{
    return 0;
    ;
}