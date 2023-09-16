#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
  double pi = 2 * acos(0.0);

  long long r1_dots = ceil(r1 * r1 * pi);
  long long r2_dots = ceil(r2 * r2 * pi);

  long long result = r2_dots - r1_dots + 4;

  return result;
}

int main()
{
  return 0;
}
