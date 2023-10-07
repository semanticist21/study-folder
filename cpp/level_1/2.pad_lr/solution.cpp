#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    bool is_left_handed = hand != "right" ? true : false;

    vector<int> left = {1, 4, 7, -1};
    vector<int> neutral = {2, 5, 8, 0};
    vector<int> right = {3, 6, 9, -1};

    vector<vector<int>> keypad = {left, neutral, right};

    int left_cur = -1;
    int right_cur = -1;

    vector<char> moves;
    moves.reserve(numbers.size());

    auto change = [&](int &original, int target, char value)
    {
        original = target;
        moves.emplace_back(value);
    };

    for (const int &num : numbers)
    {
        bool is_left = find(keypad[0].begin(), keypad[0].end(), num) != keypad[0].end();
        bool is_neutral = find(keypad[1].begin(), keypad[1].end(), num) != keypad[1].end();
        bool is_right = find(keypad[2].begin(), keypad[2].end(), num) != keypad[2].end();

        if (is_left)
            change(left_cur, num, 'L');
        else if (is_right)
            change(right_cur, num, 'R');
        else
        {
            pair<int, int> l_position;
            pair<int, int> n_position;
            pair<int, int> r_position;

            for (int i = 0; i < keypad.size(); i++)
                for (int j = 0; j < keypad[i].size(); j++)
                {
                    if (keypad[i][j] == left_cur)
                        l_position = make_pair(i, j);
                    if (keypad[i][j] == num)
                        n_position = make_pair(i, j);
                    if (keypad[i][j] == right_cur)
                        r_position = make_pair(i, j);
                }

            int l_gap = abs(l_position.first - n_position.first) + abs(l_position.second - n_position.second);
            int r_gap = abs(r_position.first - n_position.first) + abs(r_position.second - n_position.second);

            if (l_gap == r_gap)
            {
                if (is_left_handed)
                    change(left_cur, num, 'L');
                else
                    change(right_cur, num, 'R');
            }
            else if (l_gap < r_gap)
                change(left_cur, num, 'L');
            else
                change(right_cur, num, 'R');
        }
    }

    return string(moves.begin(), moves.end());
}

int main()
{
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";
    auto rs = solution(numbers, hand);
    cout << rs << endl;

    return 0;
}