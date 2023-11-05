#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<vector<int>> sets;

    vector<int> temp;
    vector<char> int_chars;

    for (const char &c : s)
    {
        if (isdigit(c))
        {
            int_chars.emplace_back(c);
        }
        else if (c == ',')
        {
            if (int_chars.empty())
                continue;

            string s(int_chars.begin(), int_chars.end());
            int_chars = vector<char>();
            temp.emplace_back(stoi(s));
        }
        else if (c == '}')
        {
            if (!int_chars.empty())
            {
                string s(int_chars.begin(), int_chars.end());
                int_chars = vector<char>();
                temp.emplace_back(stoi(s));
            }

            if (!temp.empty())
            {
                sets.emplace_back(temp);
                temp = vector<int>();
            }
        }
    }

    auto compare = [](vector<int> a, vector<int> b)
    {
        return a.size() < b.size();
    };

    sort(sets.begin(), sets.end(), compare);

    vector<int> answer;

    for (const vector<int> set : sets)
    {
        for (const int item : set)
            if (find(answer.begin(), answer.end(), item) == answer.end())
            {
                answer.emplace_back(item);
            }
    }

    return answer;
}

int main()
{
    return 0;
}