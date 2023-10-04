#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    return 0;
}

vector<string> solution(vector<string> players, vector<string> callings)
{
    map<string, int> d;

    for (int i = 0; i < players.size(); i++)
    {
        d[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++)
    {
        string call = callings[i];
        int idx = d[call];

        string origin = players[idx - 1];
        players[idx - 1] = players[idx];
        players[idx] = origin;

        d[call] = idx - 1;
        d[origin] = idx;
    }

    vector<string> answer(players.size());

    for (const pair<string, int> p : d)
    {
        answer[p.second] = p.first;
    }

    return answer;
}
