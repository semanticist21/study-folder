#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(vector<vector<string>> plans)
{
    vector<vector<string>> plans_;

    for (const auto &plan : plans)
    {
        string hour = plan[1].substr(0, 2);
        string min = plan[1].substr(3, 2);

        vector<string> cvt_plan = {
            plan[0],
            to_string(stoi(hour) * 60 + stoi(min)),
            plan[2],
        };

        plans_.push_back(cvt_plan);
    };

    auto compare = [](vector<string> a, vector<string> b)
    {
        return stoi(a[1]) < stoi(b[1]);
    };

    sort(plans_.begin(), plans_.end(), compare);

    vector<string> remnants;
    vector<string> completed;

    for (int i = 0; i < plans_.size(); i++)
    {
        if (i == plans_.size() - 1)
        {
            completed.push_back(plans_[i][0]);
            break;
        }

        auto item = plans_[i];
        auto next = plans_[i + 1];

        int gap = stoi(next[1]) - stoi(item[1]);

        if (stoi(item[2]) <= gap)
        {
            completed.push_back(item[0]);
        }
        else
        {
            remnants.push_back(item[0]);
        }
    }

    while (remnants.size())
    {
        completed.push_back(remnants.back());
        remnants.pop_back();
    }

    return completed;
}

int main()
{
    vector<vector<string>> data = {{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};
    auto result = solution(data);

    for (const auto &item : result)
    {
        cout << item << endl;
    }
    return 0;
}