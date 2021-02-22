/*
������ ���� ���� n�� ����, n�� � ���� ���� x�� �������� �ƴ��� �Ǵ��Ϸ� �մϴ�.
n�� ���� ���� x�� �����̶�� x+1�� ������ �����ϰ�, n�� ���� ���� x�� ������ �ƴ϶�� -1�� �����ϴ� �Լ��� �ϼ��ϼ���.
*/

#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long count = 1;

    while (true) {
        if (n == count * count) {
            answer = (count + 1) * (count + 1);
            break;
        }

        if (n < count * count) {
            answer = -1;
            break;
        }

        count++;
    }

    return answer;
}