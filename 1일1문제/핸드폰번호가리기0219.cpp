/*
���α׷��ӽ� ������� �������� ��ȣ�� ���� �������� ���� �� ������ ��ȭ��ȣ�� �Ϻθ� �����ϴ�.
��ȭ��ȣ�� ���ڿ� phone_number�� �־����� ��, ��ȭ��ȣ�� �� 4�ڸ��� ������ ������ ���ڸ� ���� *���� ���� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int length = 0;

    length = phone_number.length() - 4;

    for (int i = 0; i < length; i++) {
        answer.push_back('*');
    }

    for (int i = length; i < length + 4; i++) {
        answer.push_back(phone_number[i]);
    }

    return answer;
}