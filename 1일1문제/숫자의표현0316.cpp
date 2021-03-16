/*
Finn�� ���� ���а��ο� ���� �ֽ��ϴ�. ���� ���θ� �ϴ� Finn�� �ڿ��� n�� ������ �ڿ������ ǥ�� �ϴ� ����� ��������� ����� �˰� �Ǿ����ϴ�. ������� 15�� ������ ���� 4������ ǥ�� �� �� �ֽ��ϴ�.

1 + 2 + 3 + 4 + 5 = 15
4 + 5 + 6 = 15
7 + 8 = 15
15 = 15
�ڿ��� n�� �Ű������� �־��� ��, ���ӵ� �ڿ������ n�� ǥ���ϴ� ����� ���� return�ϴ� solution�� �ϼ����ּ���.

���ѻ���
n�� 10,000 ������ �ڿ��� �Դϴ�.

2�߷���?
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;

    for (int i = 1; i < n; i++) {
        sum = i;
        if (i == n - 1) {
            answer++;
            break;
        }

        for (int j = i + 1; j < n; j++) {
            sum += j;

            if (sum == n) {
                answer++;
                break;
            }

            if (sum > n) {
                break;
            }
        }
    }

    return answer;
}