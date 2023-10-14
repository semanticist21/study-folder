#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    unordered_map<int, int> size_map;

    for (const int &t : tangerine)
        size_map[t] += 1;

    auto compare = [](pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    };

    vector<pair<int, int>> map_vector(size_map.begin(), size_map.end());
    sort(map_vector.begin(), map_vector.end(), compare);

    int result = 0;
    int stacked = 0;

    for (const auto &pair : map_vector)
    {
        stacked += pair.second;

        result++;
        if (stacked >= k)
            break;
    }

    return result;
}

int main()
{
    vector<int> input = {1, 3, 2, 5, 4, 5, 2, 3};
    int val = 4;

    auto rs = solution(val, input);

    return 0;
}