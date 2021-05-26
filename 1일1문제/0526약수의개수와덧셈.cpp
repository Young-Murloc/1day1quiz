/*
�� ���� left�� right�� �Ű������� �־����ϴ�. left���� right������ ��� ���� �߿���, ����� ������ ¦���� ���� ���ϰ�, ����� ������ Ȧ���� ���� �� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

��� ���ϴ� ����ȭ�� ��� ���
*/

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int count = 0;

    int j = 0;

    for (int i = left; i <= right; i++) {
        count = 0;
        j = 0;

        for (j = 1; j * j < i; j++) {
            if (i % j == 0) {
                count += 2;
            }
        }

        if (j * j == i) {
            count++;
        }

        if (count % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }

    return answer;
}