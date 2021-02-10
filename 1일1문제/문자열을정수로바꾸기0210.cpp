/*
문자열 s를 숫자로 변환한 결과를 반환하는 함수, solution을 완성하세요.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i = 0;
    bool sign = true;
    int count = 0;

    if (s.length() == 5) {
        count = 10000;
    }
    else if (s.length() == 4) {
        count = 1000;
    }
    else if (s.length() == 3) {
        count = 100;
    }
    else if (s.length() == 2) {
        count = 10;
    }
    else {
        count = 1;
    }

    if (s[0] == '+') {
        sign = true;
        i = 1;
        count *= 0.1;
    }
    else if (s[0] == '-') {
        sign = false;
        i = 1;
        count *= 0.1;
    }

    for (i; i < s.length(); i++) {
        answer += (int(s[i]) - 48) * count;
        count *= 0.1;
    }

    if (sign == false) {
        answer *= -1;
    }

    return answer;
}