/*
문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.
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

        if (check == true) {      //짝
            if (int(s[i]) >= 97 && int(s[i]) <= 122) {
                s[i] = int(s[i]) - 32;
            }
        }
        else {                   //홀
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