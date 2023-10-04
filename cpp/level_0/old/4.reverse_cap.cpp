#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
  string str;
  cin >> str;

  string word;

  for (char c : str)
  {
    if (isupper(c))
    {
      word += (char)tolower(c);
      continue;
    }

    word += (char)toupper(c);
  }

  cout << word << endl;

  return 0;
}