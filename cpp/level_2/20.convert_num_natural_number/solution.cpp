#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n)
{
    unordered_set<int> sums;
    unordered_set<int> new_sums;
    sums.insert(x);

    int answer = 0;

    if(x == y) return 0;

    while(!sums.empty()){
        ++answer;

        for(const int prev_sum : sums){
            if(prev_sum > y) continue;

            new_sums.insert(prev_sum*2);
            new_sums.insert(prev_sum*3);
            new_sums.insert(prev_sum+n);
        }

        sums.clear();

        for(const int new_sum : new_sums){
            if(new_sum == y) return answer;
            else sums.insert(new_sum);
        }

        new_sums.clear();
    }

    return -1;
}

int main()
{
    return 0;
}