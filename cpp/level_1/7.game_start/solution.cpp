#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult)
{
    vector<int> scores;

    for (int i = 0; i < dartResult.size(); i++)
    {
        int score = dartResult[i] - '0';
        char next = dartResult[i + 1];

        if (isdigit(next))
        {
            char over_next = dartResult[i + 2];
            score = 10;

            if (over_next == 'D')
                score = pow(score, 2);
            else if (over_next == 'T')
                score = pow(score, 3);
            i++;
        }
        else
        {
            if (next == 'D')
                score = pow(score, 2);
            else if (next == 'T')
                score = pow(score, 3);
        }

        char potential_special = dartResult[i + 2];
        i++;

        if (potential_special != '*' && potential_special != '#')
        {
            scores.emplace_back(score);
            continue;
        }

        i++;
        if (potential_special == '*')
        {
            if (!scores.empty())
                scores.back() *= 2;
            score *= 2;
        }
        else
        {
            score *= -1;
        }
        scores.emplace_back(score);
    }

    int total = 0;
    for (const int &s : scores)
        total += s;

    return total;
}

int main()
{
    string a = "1D2S#10S";
    auto rs = solution(a);

    cout << rs << endl;

    return 0;
}