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

    vector<vector<string>> remnants;
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
        int consuming_time = stoi(item[2]);

        if (consuming_time <= gap)
        {
            completed.push_back(item[0]);
            if (remnants.empty())
            {
                continue;
            }

            if (gap == consuming_time)
            {
                continue;
            }

            int free_time = gap - consuming_time;

            while (!remnants.empty() && free_time != 0)
            {
                vector<string> last_item = remnants.back();

                if (free_time >= stoi(last_item[2]))
                {
                    free_time -= stoi(last_item[2]);
                    completed.push_back(last_item[0]);
                    remnants.pop_back();
                }
                else
                {
                    int new_remnant = stoi(last_item[2]) - free_time;
                    remnants.back()[2] = to_string(new_remnant);
                    free_time = 0;
                }
            }
        }
        else
        {
            int remained = consuming_time - gap;

            item[2] = to_string(remained);
            remnants.push_back(item);
        }
    }

    while (remnants.size())
    {
        completed.push_back(remnants.back()[0]);
        remnants.pop_back();
    }

    return completed;
}

int main()
{
    vector<vector<string>> data = {{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};
    auto result = solution(data);

    for (const string &str : result)
    {
        cout << str << endl;
    }
    return 0;
}