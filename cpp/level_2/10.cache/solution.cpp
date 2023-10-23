#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
        return cities.size() * 5;

    for (string &s : cities)
        for (char &c : s)
            c = tolower(c);

    unordered_map<string, int> recent_map;

    vector<string> cache;
    cache.reserve(cacheSize);

    int total = 0;

    for (int i = 0; i < cities.size(); i++)
    {
        if (find(cache.begin(), cache.end(), cities[i]) != cache.end())
        {
            recent_map[cities[i]] = i;
            total++;
            continue;
        }

        if (cache.size() < cacheSize)
        {
            cache.emplace_back(cities[i]);
            recent_map[cities[i]] = i;
            total += 5;
            continue;
        }

        int to_replace = -1;
        int minimum = 0x7fffffff;

        for (int j = 0; j < cache.size(); j++)
        {
            if (recent_map[cache[j]] < minimum)
            {
                to_replace = j;
                minimum = recent_map[cache[j]];
            }
        }

        cache[to_replace] = cities[i];
        recent_map[cities[i]] = i;
        total += 5;
    }

    return total;
}

int main()
{
    return 0;
}