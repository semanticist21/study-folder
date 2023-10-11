#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    answer.reserve(commands.size());

    for (vector<int> &command : commands)
    {
        command[0] -= 1;

        vector<int> clone(array.begin() + command[0], array.begin() + command[1]);

        sort(clone.begin(), clone.end());
        answer.emplace_back(clone[command[2] - 1]);
    }

    return answer;
}

int main()
{
    vector<int> first = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    auto rs = solution(first, commands);

    return 0;
}
