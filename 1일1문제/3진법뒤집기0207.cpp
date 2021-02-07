/*
�ڿ��� n�� �Ű������� �־����ϴ�. n�� 3���� �󿡼� �յڷ� ������ ��, �̸� �ٽ� 10�������� ǥ���� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.
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