#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance)
{
    int max = 0x7fffffff;

    vector<pair<int, int>> ranks(rank.size());

    for (int i = 0; i < rank.size(); i++)
    {
        if (attendance[i])
            ranks[i] = make_pair(rank[i], i);
        else
            ranks[i] = make_pair(max, i);
    }

    auto compare = [](pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    };

    sort(ranks.begin(), ranks.end(), compare);

    return ranks[0].second * 10000 + ranks[1].second * 100 + ranks[2].second;
}

int main()
{
    return 0;
}