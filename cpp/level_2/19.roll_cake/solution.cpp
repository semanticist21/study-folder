#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> topping)
{
    unordered_map<int, int> self;
    unordered_map<int, int> brother;

    self[topping[0]] = 1;

    int self_topping_cnt = 1;
    int brother_topping_cnt = 0;

    for (int i = 1; i < topping.size(); i++)
        brother[topping[i]] += 1;

    for (const pair<int, int> &p : brother)
        if (p.second) brother_topping_cnt++;

    int cnt = 0;
    for (int i = 1; i < topping.size(); i++)
    {
        self[topping[i]] += 1;
        brother[topping[i]] -= 1;

        if(self[topping[i]] == 1) self_topping_cnt++;
        if(!brother[topping[i]]) brother_topping_cnt--;

        if(self_topping_cnt == brother_topping_cnt) cnt++;
    }

    return cnt;
}

int main()
{
    return 0;
}