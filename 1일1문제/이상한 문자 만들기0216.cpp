/*
���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. �� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. �� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    bool check = true;

    for (int i = 0; i < s.size(); i++) {
        if (int(s[i]) == 32) {
            check = true;
        }

        if (check == true) {      //¦
            if (int(s[i]) >= 97 && int(s[i]) <= 122) {
                s[i] = int(s[i]) - 32;
            }
        }
        else {                   //Ȧ
            if (int(s[i]) >= 65 && int(s[i]) <= 90) {
                s[i] = int(s[i]) + 32;
            }
        }

        if (int(s[i]) != 32) {
            if (check) {
                check = false;
            }
            else {
                check = true;
            }
        }
    }

    return s;
}