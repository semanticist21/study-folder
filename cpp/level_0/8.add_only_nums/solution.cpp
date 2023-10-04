#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int solution(string my_string)
{
  int answer = 0;

  for (const char &c : my_string)
  {
    if (!isdigit(c))
      continue;

    answer += c - '0';
  }

  return answer;
}

int main()
{
  auto rs = solution("aAb1B2cC34oOp");

  cout << rs << endl;
  return 0;
}