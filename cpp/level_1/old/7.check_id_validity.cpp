#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    auto check_lambda = [](char c)
    {
        bool is_char = (c >= 'a' && c <= 'z');
        bool is_num = (c >= '0' && c <= '9');
        bool is_special = (c == '-' || c == '_' || c == '.');

        return !(is_char || is_num || is_special);
    };

    auto remove_iter = remove_if(new_id.begin(), new_id.end(), check_lambda);
    new_id.erase(remove_iter, new_id.end());

    while (new_id.find("..") != string::npos)
    {
        size_t pos = new_id.find("..");
        new_id.replace(pos, 2, ".");
    }

    if (!new_id.empty() && new_id.front() == '.')
    {
        new_id.erase(new_id.begin());
    }

    if (!new_id.empty() && new_id.back() == '.')
    {
        new_id.pop_back();
    }

    if (new_id.empty())
    {
        new_id = "a";
    }

    if (new_id.length() >= 16)
    {
        new_id = new_id.substr(0, 15);
        new_id = new_id.back() == '.' ? new_id.substr(0, 14) : new_id;
    }

    if (new_id.length() <= 2)
    {
        int gap = 3 - new_id.length();
        new_id += string(gap, new_id.back());
    }

    return new_id;
}

int main()
{
    string result = solution("...!@BaT#*..y.abcdefghijklm");
    cout << result << endl;
    return 0;
}