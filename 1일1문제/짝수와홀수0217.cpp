/*
���� num�� ¦���� ��� Even�� ��ȯ�ϰ� Ȧ���� ��� Odd�� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.
*/
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";

    if (num % 2 == 0) {
        answer = "Even";
    }
    else {
        answer = "Odd";
    }

    return answer;
}