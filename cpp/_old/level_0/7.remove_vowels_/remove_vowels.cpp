#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

string solution(string my_string)
{
  unordered_set<char> m = {'a', 'e', 'i', 'o', 'u'};

  vector<char> answer;
  answer.reserve(my_string.size());

  for (const char &c : my_string)
  {
    if (m.find(c) == m.end())
      answer.push_back(c);
    else
      continue;
  }

  return string(answer.begin(), answer.end());
}

string solution_(string my_string)
{
  return regex_replace(my_string, regex("[aeiou]+"), "");
}

int main()
{
  auto rs = solution_("nice to meet you");
  cout << rs << endl;
  return 0;
}