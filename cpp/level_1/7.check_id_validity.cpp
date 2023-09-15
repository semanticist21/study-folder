#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_valid(char c)
{
    bool is_valid_special = c == '-' || c == '_' || c == '.';
    bool is_valid_number = c >= '0' && c <= '9';

    return is_valid_special || is_valid_number;
}

string solution(string new_id)
{
    transform(new_id.begin(), new_id.end(), new_id.begin(), [](unsigned char c)
              { return tolower(c); });

    new_id.erase(remove_if(new_id.begin(), new_id.end(), [](unsigned char c)
                           { return !is_valid(c); }));

    new_id.replace(new_id.begin(), new_id.end(), "..", ".");

    if (new_id[0] == '.')
    {
        new_id.erase(new_id.begin());
    }

    if (new_id[new_id.size() - 1] == '.')
    {
        new_id.erase(new_id.end());
    }

    if (new_id == "")
    {
        new_id = "a";
    }

    if (new_id.size() >= 16)
    {
        new_id.erase(new_id.begin() + 15, new_id.end());
    }

    if (new_id[new_id.size() - 1] == '.')
    {
        new_id.erase(new_id.end());
    }

    if (new_id.size() <= 2)
    {
        int gap = 3 - new_id.size();
        new_id += string(gap, new_id[new_id.size() - 1]);
    }

    return new_id;
}

int main()
{
    string result = solution("asdadasdassd");
    cout << result << endl;
    return 0;
}