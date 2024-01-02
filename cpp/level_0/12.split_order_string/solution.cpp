#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString)
{
    vector<string> answer;
    vector<char> temp;

    for (int i = 0; i < myString.size(); i++)
    {
        char c = myString[i];

        if (c == 'x' || i == myString.size() - 1)
        {
            if(i == myString.size() - 1 && c != 'x') temp.emplace_back(c);

            if (temp.empty())
                continue;

            string s(temp.begin(), temp.end());
            answer.emplace_back(s);
            temp.clear();

            continue;
        }

        temp.emplace_back(c);
    }

    auto compare = [](string a, string b)
    {
        return a < b;
    };

    sort(answer.begin(), answer.end(), compare);

    return answer;
}

int main()
{
    return 0;
}