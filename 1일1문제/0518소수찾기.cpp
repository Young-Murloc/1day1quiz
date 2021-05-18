/*
1���� �Է¹��� ���� n ���̿� �ִ� �Ҽ��� ������ ��ȯ�ϴ� �Լ�, solution�� ����� ������.

�Ҽ��� 1�� �ڱ� �ڽ����θ� ���������� ���� �ǹ��մϴ�.
(1�� �Ҽ��� �ƴմϴ�.)

���� ����
n�� 2�̻� 1000000������ �ڿ����Դϴ�.

�����佺��ü ���
*/

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int prime[n];

    for (int i = 2; i <= n; i++)
        prime[i] = i;

    for (int i = 2; i <= sqrt(n); i++) {
        if (prime[i] == 0)
            continue;

        for (int j = i * i; j <= n; j += i)
            prime[j] = 0;
    }

    for (int i = 2; i <= n; i++)
        if (prime[i] != 0)
            answer++;

    return answer;
}