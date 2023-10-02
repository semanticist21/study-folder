#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

int get_point(vector<string> &minerals)
{
    int point = 0;

    const int weight_table[3] = {31, 6, 1};

    for (const string &stone : minerals)
    {
        if (stone == "diamond")
            point += weight_table[0];
        else if (stone == "iron")
            point += weight_table[1];
        else
            point += weight_table[2];
    }

    return point;
}

int solution(vector<int> picks, vector<string> minerals)
{
    int total = 0;
    for (const int &pick : picks)
    {
        total += pick;
    }

    double mineral_cycle = static_cast<double>(minerals.size()) / 5;
    int cycle = ceil(mineral_cycle) < total ? ceil(mineral_cycle) : total;

    if (minerals.size() > cycle * 5)
    {
        minerals.erase(minerals.begin() + cycle * 5, minerals.end());
    }

    vector<vector<string>> w_map(cycle, vector<string>());

    for (int i = 0; i < minerals.size(); i++)
    {
        w_map[i / 5].push_back(minerals[i]);
    }

    auto comp = [](vector<string> &a, vector<string> &b)
    {
        return get_point(a) > get_point(b);
    };

    sort(w_map.begin(), w_map.end(), comp);

    const int dia_pick[3] = {1, 1, 1};
    const int iron_pick[3] = {5, 1, 1};
    const int stone_pick[3] = {25, 5, 1};

    int cost = 0;
    for (const vector<string> &pair : w_map)
    {
        const int *table;
        if (picks[0] > 0 && picks[0]--)
            table = dia_pick;
        else if (picks[1] > 0 && picks[1]--)
            table = iron_pick;
        else
            table = stone_pick;

        for (const string &mineral : pair)
        {
            if (mineral == "diamond")
                cost += table[0];
            else if (mineral == "iron")
                cost += table[1];
            else
                cost += table[2];
        }
    }

    return cost;
}

// other solution
unordered_map<string, int> dic[3] = {
    {{"diamond", 1}, {"iron", 1}, {"stone", 1}},
    {{"diamond", 5}, {"iron", 1}, {"stone", 1}},
    {{"diamond", 25}, {"iron", 5}, {"stone", 1}}};

int solution_(vector<int> picks, vector<string> minerals)
{
    auto calc = [&](int idx, int tool) -> int
    {
        int ret = 0;
        for (int i = 0; i < 5 && idx + i < minerals.size(); ++i)
            ret += dic[tool][minerals[idx + i]];

        return ret;
    };

    auto go = [&](auto &self, int a, int b, int c, int idx = 0) -> int
    {
        if (a + b + c == 0 || idx >= minerals.size())
            return 0;

        int ret = 0x7fffffff;
        if (a)
            ret = min(ret, calc(idx, 0) + self(self, a - 1, b, c, idx + 5));
        if (b)
            ret = min(ret, calc(idx, 1) + self(self, a, b - 1, c, idx + 5));
        if (c)
            ret = min(ret, calc(idx, 2) + self(self, a, b, c - 1, idx + 5));

        return ret;
    };

    return go(go, picks[0], picks[1], picks[2]);
}

int main()
{
    vector<int> picks = {1, 3, 2};
    vector<string> minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};

    int min = solution_(picks, minerals);
    cout << min << endl;

    return 0;
}