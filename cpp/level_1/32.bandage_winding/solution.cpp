#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int max_health = health;
    int last_atk_time = 0;

    for (const vector<int> &attack : attacks)
    {
        int atk_time = attack[0];
        int dmg = attack[1];

        int gap = atk_time - last_atk_time;
        health += gap * bandage[1];
        health += gap * (gap / bandage[0]) * bandage[2];

        if(max_health > health) health = max_health;

        if(dmg >= health) return -1;

        health -= dmg;
        last_atk_time = atk_time;
    }

    return health;
}

int main()
{
    return 0;
}