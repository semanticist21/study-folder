#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> stucked(N + 1, 0);
    vector<int> challengers(N + 1, 0);

    for (int i = 0; i < stages.size(); ++i)
        stucked[stages[i] - 1] += 1;

    challengers.back() = stucked.back();

    for (int i = challengers.size() - 2; i >= 0; --i)
        challengers[i] += challengers[i + 1] + stucked[i];

    vector<double> failures(N, 0);
    for (int i = 0; i < failures.size(); ++i)
    {
        if (challengers[i] == 0)
        {
            failures[i] = 0;

            continue;
        }

        failures[i] = static_cast<double>(stucked[i]) / static_cast<double>(challengers[i]);
    }

    vector<pair<int, double>> p_s_match(N, make_pair(0, 0));

    for (int i = 0; i < failures.size(); ++i)
        p_s_match[i] = make_pair(i, failures[i]);

    auto sorter = [](pair<int, double> a, pair<int, double> b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    };
    sort(p_s_match.begin(), p_s_match.end(), sorter);

    vector<int> answer(N, 0);

    for (int i = 0; i < p_s_match.size(); ++i)
        answer[i] = p_s_match[i].first + 1;

    return answer;
}

int main()
{
    int N = 40;
    vector<int> stages = {40};

    auto rs = solution(N, stages);
    for (const int &r : rs)
        cout << r << endl;

    return 0;
}