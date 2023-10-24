#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

int solution(string str1, string str2)
{
    for (char &c : str1)
        if (isalpha(c))
            c = tolower(c);

    for (char &c : str2)
        if (isalpha(c))
            c = tolower(c);

    unordered_map<string, int> str1_elements;
    unordered_map<string, int> str2_elements;

    for (int i = 0; i < str1.size()-1; i++)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            string s;
            s += str1[i];
            s += str1[i + 1];
            str1_elements[s] += 1;
        }
    }

    for (int i = 0; i < str2.size()-1; i++)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            string s;
            s += str2[i];
            s += str2[i + 1];
            str2_elements[s] += 1;
        }
    }

    int cross = 0;
    for(const pair<string, int> &p : str1_elements){
        if(str2_elements.find(p.first) == str2_elements.end()) continue;
        cross += min(p.second, str2_elements[p.first]);
    }

    int total = 0;
    for(const pair<string, int> p : str1_elements){
        if(str2_elements.find(p.first) == str2_elements.end()) total += p.second;
        else total += max(p.second, str2_elements[p.first]);
    }

    for(const pair<string, int> p : str2_elements){
        if(str1_elements.find(p.first) != str1_elements.end()) continue;
        else total += p.second;
    }

    if(total == 0) return 65536;
    double jarcard =  (double)cross / total;
    int answer = floor(jarcard * 65536);

    return answer;
}

int main()
{
    return 0;
}