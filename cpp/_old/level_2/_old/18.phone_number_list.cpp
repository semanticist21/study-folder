#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
  sort(phone_book.begin(), phone_book.end());

  unordered_set<string> m;

  for (const string &str : phone_book)
  {
    for (int i = 0; i < str.size(); i++)
    {
      string target = str.substr(0, i);

      if (m.find(target) != m.end())
      {
        return false;
      }
    }

    m.insert(str);
  }

  return true;
}

bool solution_(vector<string> phoneBook)
{
  sort(phoneBook.begin(), phoneBook.end());

  for (int i = 0; i < phoneBook.size() - 1; i++)
  {
    if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
      return false;
  }

  return true;
}

int main()
{
  vector<string> phones = {"12", "123", "1235", "567", "88"};
  bool rs = solution(phones);
  cout << rs << endl;

  return 0;
}
