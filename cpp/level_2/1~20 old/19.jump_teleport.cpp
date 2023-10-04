#include <iostream>

using namespace std;

int solution(int n)
{
  int fuel = 0;

  while (n != 0)
  {
    if (n % 2 == 0)
    {
      n = n / 2;
    }
    else
    {
      n -= 1;
      fuel++;
    }
  }

  return fuel;
}

int solution_(int n)
{
  int ans = 0;
  while (n > 0)
  {
    ans += n % 2;
    n /= 2;
  }
  return ans;
}

int solution__(int n)
{
  return __builtin_popcount(n);
}

int main()
{
  int rs = solution__(10000000);
  cout << rs << endl;
  return 0;
}