#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
  return 0;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
  int zero_count = 0;

  for (const int &i : lottos)
  {
    if (i == 0)
      ++zero_count;
  }

  map<int, bool> dic;

  for (const int &i : win_nums)
  {
    dic[i] = true;
  }

  int match_count = 0;

  for (int i = 0; i < lottos.size(); i++)
  {
    if (dic.find(lottos[i]) != dic.end())
    {
      ++match_count;
    }
  }

  int maximum = match_count + zero_count;

  int max_rank = 7 - maximum;
  int min_rank = 7 - match_count;

  if (max_rank > 6)
    max_rank = 6;

  if (min_rank > 6)
    min_rank = 6;

  return {max_rank, min_rank};
}