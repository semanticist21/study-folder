#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2)
{
  long r1_pow = r1 * (long)r1;
  long r2_pow = r2 * (long)r2;

  long on_line = 0;
  long r1_dots = 0;
  for (int i = 1; i < r1; ++i)
  {
    long i_pow = (long)i * i;
    double sqrt_val = sqrt(r1_pow - i_pow);

    if (fmod(sqrt_val, 1) == 0)
    {
      ++on_line;
    }

    r1_dots += floor(sqrt_val);
  }

  long r2_dots = 0;
  for (int i = 1; i < r2; ++i)
  {
    long i_pow = (long)i * i;
    r2_dots += floor(sqrt(r2_pow - i_pow));
  }

  long r1_total = r1_dots * 4 + r1 * 4 + 1;
  long r2_total = r2_dots * 4 + r2 * 4 + 1;

  return r2_total - r1_total + 4 + on_line * 4;
}

int main()
{
  auto result = solution(25, 39);
  cout << result << endl;
  return 0;
}
