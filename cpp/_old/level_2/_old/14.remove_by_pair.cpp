#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
  int flag = 1;

  char prev = '\0';

  if (s.size() <= 1)
    return 0;

  vector<char> unmatched(0);

  for (int i = 0; i < s.size(); i++)
  {
    char cur = s[i];

    if (unmatched.size() && unmatched.back() == cur)
    {
      unmatched.pop_back();
      continue;
    }

    if (i == s.size() - 1)
    {
      unmatched.push_back(cur);
      continue;
    }

    char next = s[i + 1];

    if (cur != next)
    {
      unmatched.push_back(cur);
      continue;
    }

    if (cur == next)
    {
      i = i + 1;
      continue;
    }
  }

  if (unmatched.size() != 0)
    return 0;
  else
    return 1;
}

int solution_(string s)
{
  stack<char> c;

  for (int i = 0; i < s.size(); i++)
  {
    if (c.size() == 0)
    {
      c.push(s[i]);
      continue;
    }

    if (c.top() == s[i])
    {
      c.pop();
    }
    else
    {
      c.push(s[i]);
    }
  }

  if (c.empty())
    return 1;
  else
    return 0;
}

int main()
{
  auto rs = solution("aaaa");
  cout << rs << endl;
  return 0;
}