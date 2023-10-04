#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(vector<int> array)
{
  sort(array.begin(), array.end());
  return array[array.size() / 2];
}

int main()
{
  return 0;
}