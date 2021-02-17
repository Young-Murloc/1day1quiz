/*
���� ���� x�� �ϻ��� ���̷��� x�� �ڸ����� ������ x�� ���������� �մϴ�. ���� ��� 18�� �ڸ��� ���� 1+8=9�̰�, 18�� 9�� ������ �������Ƿ� 18�� �ϻ��� ���Դϴ�. �ڿ��� x�� �Է¹޾� x�� �ϻ��� ������ �ƴ��� �˻��ϴ� �Լ�, solution�� �ϼ����ּ���.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int num = 0;

    num = x;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    if (x % sum != 0) {
        answer = false;
    }

    return answer;
}