// 두 정수 left와 right가 매개변수로 주어집니다.
// left부터 right까지의 모든 수들 중에서,
//  약수의 개수가 짝수인 수는 더하고,
//  약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요

#include <iostream>

using namespace std;

int get_factor_under_rule(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        int factor_count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                factor_count++;
            }
        }

        if (factor_count % 2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    return answer;
}

int main()
{
    int result_a = get_factor_under_rule(13, 17);
    int result_b = get_factor_under_rule(24, 27);

    cout << result_a << endl;
    cout << result_b << endl;

    return 0;
}
