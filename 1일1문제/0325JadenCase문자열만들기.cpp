/*
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

제한 조건
s는 길이 1 이상인 문자열입니다.
s는 알파벳과 공백문자(" ")로 이루어져 있습니다.
첫 문자가 영문이 아닐때에는 이어지는 영문은 소문자로 씁니다. ( 첫번째 입출력 예 참고 )

<포인트>
char을 int로 변환
대문자, 소문자, 숫자, 공백 고려
*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    int check = 0;              // 대문자가 있는지 확인
    int temp = 0;              // 비교용 임시 변수

    for (int i = 0; i < s.length(); i++) {
        temp = (int)s[i];

        if (temp >= 97 && temp <= 122) {          // 소문자
            if (check == 0) {
                temp -= 32;
                answer += (char)temp;
                check++;
            }
            else {
                answer += (char)temp;
            }
        }
        else if (temp >= 65 && temp <= 90) {      // 대문자
            if (check == 0) {
                answer += (char)temp;
                check++;
            }
            else {
                temp += 32;
                answer += (char)temp;
            }
        }
        else if (temp == 32) {                    // 공백
            answer += " ";
            check = 0;
        }
        else {                                   // 숫자
            answer += (char)temp;
            check++;
        }
    }

    return answer;
}