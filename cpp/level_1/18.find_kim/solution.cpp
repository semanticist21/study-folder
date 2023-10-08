#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(vector<string> seoul)
{
    ostringstream os;

    os << "김서방은 ";

    int cnt = 0;
    for (int string &str : seoul)
        if (++cnt && (str == "Kim"))
            os << cnt - 1;

    os << "에 있다";
    return os.str();
}

int main()
{
    vector<string> seoul = {"Jane", "Kim"};
    auto rs = solution(seoul);

    cout << rs << endl;
    return 0;
}