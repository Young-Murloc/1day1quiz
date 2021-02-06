/*

2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT

*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int remainder = 0;

    if (a == 1) {
        b += 0;
    }
    else if (a == 2) {
        b += 31;
    }
    else if (a == 3) {
        b += 60;
    }
    else if (a == 4) {
        b += 91;
    }
    else if (a == 5) {
        b += 121;
    }
    else if (a == 6) {
        b += 152;
    }
    else if (a == 7) {
        b += 182;
    }
    else if (a == 8) {
        b += 213;
    }
    else if (a == 9) {
        b += 244;
    }
    else if (a == 10) {
        b += 274;
    }
    else if (a == 11) {
        b += 305;
    }
    else {
        b += 335;
    }

    remainder = b % 7;

    if (remainder == 1) {
        answer = "FRI";
    }
    else if (remainder == 2) {
        answer = "SAT";
    }
    else if (remainder == 3) {
        answer = "SUN";
    }
    else if (remainder == 4) {
        answer = "MON";
    }
    else if (remainder == 5) {
        answer = "TUE";
    }
    else if (remainder == 6) {
        answer = "WED";
    }
    else {
        answer = "THU";
    }

    return answer;
}