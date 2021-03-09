/*
0�� 1�� �̷���� � ���ڿ� x�� ���� ���� ��ȯ�� ������ ���� �����մϴ�.

x�� ��� 0�� �����մϴ�.
x�� ���̸� c��� �ϸ�, x�� "c�� 2�������� ǥ���� ���ڿ�"�� �ٲߴϴ�.
���� ���, x = "0111010"�̶��, x�� ���� ��ȯ�� ���ϸ� x = "0111010" -> "1111" -> "100" �� �˴ϴ�.

0�� 1�� �̷���� ���ڿ� s�� �Ű������� �־����ϴ�. s�� "1"�� �� ������ ����ؼ� s�� ���� ��ȯ�� ������ ��, ���� ��ȯ�� Ƚ���� ��ȯ �������� ���ŵ� ��� 0�� ������ ���� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int zeroCheck(string* s) {               //������ 0�� ���� 
    int zero = 0;
    string::iterator iter = s->begin();

    while (iter != s->end()) {
        if (*iter == '0') {
            s->erase(iter);
            zero++;
        }
        else {
            iter++;
        }
    }

    return zero;
}

string tenToTwo(string s) {              //���� ��ȯ ���
    string temp = "";
    int length = s.size();

    while (length != 1) {
        if (length % 2 == 0) {
            temp.push_back('0');
        }
        else {
            temp.push_back('1');
        }

        length = length / 2;
    }

    temp.push_back('1');

    reverse(temp.begin(), temp.end());

    return temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;  //���� ��ȯ Ƚ��
    int zero = 0;   //���� ��ȯ�� ���ŵ� 0�� ����

    while (s != "1") {
        zero = zero + zeroCheck(&s);     //������ 0 ����
        s = tenToTwo(s);                //���� ��ȯ
        count++;
    }

    answer.push_back(count);
    answer.push_back(zero);

    return answer;
}