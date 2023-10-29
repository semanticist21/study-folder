#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(string dirs)
{
    auto wrap_str = [](pair<int, int> &p)
    {
        return to_string(p.first) + '_' + to_string(p.second);
    };

    pair<int, int> current = make_pair(0, 0);
    unordered_map<string, unordered_set<string>> visited;

    for (const char &c : dirs)
    {
        if (c == 'U' && current.second < 5)
        {
            pair<int, int> new_routes = make_pair(current.first, current.second + 1);
            visited[wrap_str(current)].insert(wrap_str(new_routes));
            visited[wrap_str(new_routes)].insert(wrap_str(current));

            current.second++;
        }
        else if (c == 'D' && current.second > -5)
        {
            pair<int, int> new_routes = make_pair(current.first, current.second - 1);
            visited[wrap_str(current)].insert(wrap_str(new_routes));
            visited[wrap_str(new_routes)].insert(wrap_str(current));

            current.second--;
        }
        else if (c == 'L' && current.first > -5)
        {
            pair<int, int> new_routes = make_pair(current.first - 1, current.second);
            visited[wrap_str(current)].insert(wrap_str(new_routes));
            visited[wrap_str(new_routes)].insert(wrap_str(current));

            current.first--;
        }
        else if (c == 'R' && current.first < 5)
        {
            pair<int, int> new_routes = make_pair(current.first + 1, current.second);
            visited[wrap_str(current)].insert(wrap_str(new_routes));
            visited[wrap_str(new_routes)].insert(wrap_str(current));

            current.first++;
        }
    }

    int routes = 0;
    for (const pair<string, unordered_set<string>> &p : visited)
        routes += p.second.size();

    return routes / 2;
}

int main()
{
    return 0;
}