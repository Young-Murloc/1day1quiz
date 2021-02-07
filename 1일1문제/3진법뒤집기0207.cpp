/*
자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    int quotient = 0;
    int remainder = 0;

    int multi = 1;

    vector<int> num;

    while (true) {
        if (n < 3) {
            num.push_back(n);
            break;
        }

        quotient = n / 3;
        remainder = n % 3;

        n = quotient;

        num.push_back(remainder);
    }

    for (int i = num.size() - 1; i >= 0; i--) {
        answer += num[i] * multi;
        multi *= 3;
    }

    return answer;
}