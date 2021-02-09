/*
���ڿ� s�� ���̰� 4 Ȥ�� 6�̰�, ���ڷθ� �������ִ��� Ȯ�����ִ� �Լ�, solution�� �ϼ��ϼ���. ���� ��� s�� a234�̸� False�� �����ϰ� 1234��� True�� �����ϸ� �˴ϴ�.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if (s.length() == 4 || s.length() == 6) {
        for (int i = 0; i < s.size(); i++) {
            if (int(s[i]) < 48 || int(s[i]) > 57) {
                answer = false;
                break;
            }
        }
    }
    else {
        answer = false;
    }

    return answer;
}