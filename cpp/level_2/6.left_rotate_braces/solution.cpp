#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s)
{
    vector<vector<char>> chars_col;
    for (int i = 0; i < s.size(); i++)
    {
        vector<char> chars;
        for (int j = 0; j < s.size(); j++)
        {
            chars.emplace_back(s[(i + j) % s.size()]);
        }

        chars_col.emplace_back(chars);
    }

    vector<char> right_elements = {']', '}', ')'};

    int total = 0;
    for (const vector<char> &item : chars_col)
    {
        vector<char> lefts;
        bool is_incorrect = false;

        for (int i = 0; i < item.size(); i++)
        {
            char c = item[i];

            if (c == '[' || c == '{' || c == '(')
                lefts.emplace_back(c);
            else
            {
                if (lefts.empty())
                {
                    is_incorrect = true;
                    break;
                }

                int last = lefts.back();
                if (c - last == 1 || c - last == 2)
                    lefts.pop_back();
                else
                {
                    is_incorrect = true;
                    break;
                }
            }
        }

        if (!is_incorrect && lefts.size() == 0)
            total++;
    }

    return total;
}

int main()
{
    string s = "[](){}";
    auto rs = solution(s);

    cout << rs << endl;
    return 0;
}