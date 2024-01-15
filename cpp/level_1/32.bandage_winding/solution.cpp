#include <string>
#include <vector>
#include <iostream>
#include <cmath>

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

        health += (gap-1) * bandage[1];
        health += (gap-1) / bandage[0] * bandage[2];

        if(max_health < health) health = max_health;
        
        health -= dmg;
        if(health <= 0) return -1;

        last_atk_time = atk_time;
    }

    return health;
}

int main()
{
    return 0;
}