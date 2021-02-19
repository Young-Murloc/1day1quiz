/*
프로그래머스 모바일은 개인정보 보호를 위해 고지서를 보낼 때 고객들의 전화번호의 일부를 가립니다.
전화번호가 문자열 phone_number로 주어졌을 때, 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 리턴하는 함수, solution을 완성해주세요.
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