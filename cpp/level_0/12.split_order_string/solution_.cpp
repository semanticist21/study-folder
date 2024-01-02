#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(string myString)
{
    vector<string> answer;

    for (auto &c : myString)
    {
        if (c == 'x')
        {
            c = ' ';
        }
    }

    string str;
    stringstream ss;
    ss.str(myString);
    while (ss >> str)
    {
        answer.emplace_back(str);
    }

    sort(answer.begin(), answer.end());

    return answer;
}