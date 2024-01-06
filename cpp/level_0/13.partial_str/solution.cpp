#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2)
{
    int cur = 0;

    for (const char &c : str2)
    {
        if (cur == str1.size())
            return 1;

        char t = str1[cur];

        if (t == c)
        {
            cur++;
            continue;
        }
        else
            cur = 0;

        if (str1[cur] == c)
            cur++;
    }

    if(cur == str1.size()) return 1;

    return 0;
}

int main()
{
    return 0;
}