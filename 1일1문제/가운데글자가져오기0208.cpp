/*
�ܾ� s�� ��� ���ڸ� ��ȯ�ϴ� �Լ�, solution�� ����� ������. �ܾ��� ���̰� ¦����� ��� �α��ڸ� ��ȯ�ϸ� �˴ϴ�.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    if (s.size() % 2 != 0) {          //Ȧ��
        if (s.size() == 1) {
            answer = s;
        }
        else {
            answer.push_back(s[s.size() / 2]);
        }
    }
    else {                       //¦��
        if (s.size() == 2) {
            answer = s;
        }
        else {
            answer.push_back(s[s.size() / 2 - 1]);
            answer.push_back(s[s.size() / 2]);
        }
    }

    return answer;
}