#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

int count_1(string s)
{
  int cnt = 0;

  for (const char &c : s)
  {
    if (c == '1')
      ++cnt;
  }

  return cnt;
}

int solution(int n)
{
  int i = count_1(bitset<32>(n).to_string());

  while (true)
  {
    n++;
    if (count_1(bitset<32>(n).to_string()) == i)
      break;
  }

  return n;
}

int solution_(int n)
{
  int i = bitset<32>(n).count();

  while (bitset<32>(++n).count() != i)
    ;

  return n;
}

int main()
{
  auto rs = solution_(15);

  cout << rs << endl;
  return 0;
}