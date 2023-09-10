#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
  int item_len = absolutes.size();

  for (int i = 0; i < item_len; i++)
  {
    if (!signs[i])
      absolutes[i] *= -1;
  }

  int answer = 0;

  for (const int &value : absolutes)
  {
    answer += value;
  }

  return answer;
}
//
int main()
{
  return 0;
}