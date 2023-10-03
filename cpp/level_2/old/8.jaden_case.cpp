#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
  bool is_first = true;
  for (char &c : s)
  {
    if (c == ' ')
      is_first = true;
    else if (is_first)
    {
      c = toupper(c);
      is_first = false;
    }
    else if (!is_first)
    {
      c = tolower(c);
    }
  }

  return s;
}

string solution_(string s)
{
  string answer = "";

  answer += toupper(s[0]);

  for (int i = 1; i < s.size(); i++)
    s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

  return answer;
}

int main()
{
  auto r = solution("abc abc abc abc abc eff");
  cout << r << endl;
  return 0;
}