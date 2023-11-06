#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int cnt = 0;

    for (const string &str : skill_trees)
    {
        int start = 0;

        for (const char &c : str)
        {
            if (c == skill[start])
            {
                start++;
            }
            else if (find(skill.begin(), skill.end(), c) != skill.end())
            {
                start = -1;
                break;
            }
        }

        if (start != -1)
            cnt++;
    }

    return cnt;
}

int main()
{
    return 0;
}