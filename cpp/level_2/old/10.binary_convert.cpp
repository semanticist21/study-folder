#include <bits/stdc++.h>

using namespace std;

string filter(string s, int &cnt)
{
  string new_str = "";

  for (const char &c : s)
  {
    if (c == '0')
      ++cnt;
    else
      new_str.push_back(c);
  }

  int size = new_str.size();

  bitset<32> bset(size);
  string converted = bset.to_string();

  converted = converted.substr(converted.find('1'));

  return converted;
}

vector<int> solution(string s)
{
  int cnt = 0;
  int cycle = 0;

  string c = s;

  while (c != "1")
  {
    ++cycle;
    c = filter(c, cnt);
  }

  return {cycle, cnt};
}

int main()
{
  auto rs = solution("01110");

  cout << rs[0] << " " << rs[1] << endl;
  return 0;
}