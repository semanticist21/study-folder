#include <vector>
#include <string>

using namespace std;

long long solution(long long n)
{
    vector<char> v;
    string str = to_string(n);

    for (const char &c : str)
        v.emplace_back(c);

    sort(v.rbegin(), v.rend());
    return stoll(string(v.begin(), v.end()));
}

int main()
{
    solution(799999999999);

    return 0;
}