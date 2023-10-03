#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
  return inner_product(a.begin(), a.end(), b.begin(), 0);
}

int main()
{
  return 0;
}