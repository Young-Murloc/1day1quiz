/*
���̰� n�̰�, ���ڼ��ڼ��ڼ�....�� ���� ������ �����ϴ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���. ������� n�� 4�̸� ���ڼ����� �����ϰ� 3�̶�� ���ڼ��� �����ϸ� �˴ϴ�.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    string s = "��";
    string b = "��";

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            answer.append("��");
        }
        else {
            answer.append("��");
        }
    }

    return answer;
}