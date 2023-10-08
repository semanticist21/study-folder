#include <iostream>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    int root = sqrt(n);
    bool is_root = pow(root, 2) == n;

    if (is_root)
        return pow(root + 1, 2);
    else
        return -1;
}

int main()
{
    return 0;
}