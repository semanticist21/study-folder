#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
  vector<int> memo(n + 1, -1);
  memo[0] = 0;
  memo[1] = 1;

  int nth = 2;

  while (nth <= n)
  {
    memo[nth] = (memo[nth - 1] + memo[nth++ - 2]) % 1234567;
  }

  return memo.back();
}

int main()
{
  auto rs = solution(100000000);
  cout << rs << endl;
  return 0;
}