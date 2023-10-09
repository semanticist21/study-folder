#include <vector>

using namespace std;

char toUp(char word)
{
    if (word >= 'a' && word <= 'z')
    {
        word = word - ('a' - 'A');
    }
    return word;
}

char toLow(char word)
{
    if (word >= 'A' && word <= 'Z')
    {
        word = word + ('a' - 'A');
    }
    return word;
}

string solution(string s)
{
    int idx = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            idx = 1;
            continue;
        }
        s[i] = (idx % 2 == 1) ? toUp(s[i]) : toLow(s[i]);
        idx++;
    }
    return s;
}

int main()
{
    return 0;
}