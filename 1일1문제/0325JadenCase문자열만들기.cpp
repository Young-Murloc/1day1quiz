/*
JadenCase�� ��� �ܾ��� ù ���ڰ� �빮���̰�, �� ���� ���ĺ��� �ҹ����� ���ڿ��Դϴ�. ���ڿ� s�� �־����� ��, s�� JadenCase�� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ����ּ���.

���� ����
s�� ���� 1 �̻��� ���ڿ��Դϴ�.
s�� ���ĺ��� ���鹮��(" ")�� �̷���� �ֽ��ϴ�.
ù ���ڰ� ������ �ƴҶ����� �̾����� ������ �ҹ��ڷ� ���ϴ�. ( ù��° ����� �� ���� )

<����Ʈ>
char�� int�� ��ȯ
�빮��, �ҹ���, ����, ���� ���
*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    int check = 0;              // �빮�ڰ� �ִ��� Ȯ��
    int temp = 0;              // �񱳿� �ӽ� ����

    for (int i = 0; i < s.length(); i++) {
        temp = (int)s[i];

        if (temp >= 97 && temp <= 122) {          // �ҹ���
            if (check == 0) {
                temp -= 32;
                answer += (char)temp;
                check++;
            }
            else {
                answer += (char)temp;
            }
        }
        else if (temp >= 65 && temp <= 90) {      // �빮��
            if (check == 0) {
                answer += (char)temp;
                check++;
            }
            else {
                temp += 32;
                answer += (char)temp;
            }
        }
        else if (temp == 32) {                    // ����
            answer += " ";
            check = 0;
        }
        else {                                   // ����
            answer += (char)temp;
            check++;
        }
    }

    return answer;
}