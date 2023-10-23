#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k)
{
    vector<string> answer;

    for (const string &s : picture)
    {
        vector<char> new_str;
        new_str.reserve(s.size() * k);

        for (const char &c : s)
            for (int i = 0; i < k; i++)
                new_str.emplace_back(c);

        for (int i = 0; i < k; i++)
            answer.emplace_back(string(new_str.begin(), new_str.end()));
    }

    return answer;
}

int main()
{
    return 0;
}